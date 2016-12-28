
// Modified by Sung, www.sunglab.com
// Copyright (c) 2008-2012 Memo Akten, www.memo.tvn

#include "Fluid.h"


StarFluid::StarFluid()
:density(NULL)
,densityOld(NULL)
,uv(NULL)
,uvOld(NULL)
,color(NULL)
,colorOld(NULL)
,_isInited(false)
{
//    starLOG("ok?");
    custom_brush[0]  = (float*)0;
    custom_brush[1] = (float*)0;
    custom_brush[2] = (float*)0;
    custom_brush_radius[0] = 0;
    custom_brush_radius[1] = 0;
    custom_brush_radius[2] = 0;
}

StarFluid& StarFluid::setSize(int NX, int NY)
{
    _NX = NX;
    _NY = NY;
    _numCells = (_NX + 2) * (_NY + 2);
    
    _invNX = 1.0f / _NX;
    _invNY = 1.0f / _NY;
    _invNumCells = 1.0f / _numCells;
    
    width           = getWidth();
    height          = getHeight();
    invWidth        = 1.0f/width;
    invHeight       = 1.0f/height;
    
    reset();
    return *this;
}


StarFluid& StarFluid::setup(int NX, int NY)
{
    
    setDeltaT();
    setFadeSpeed();
    setSolverIterations();
//    setWrap( true, true );
    setWrap(false,false);
    
    //maa
    viscocity =  FLUID_DEFAULT_VISC;
    
    return setSize( NX, NY);
}

StarFluid&  StarFluid::setDeltaT(float deltaT) {
    this->deltaT = deltaT;
    return *this;
}

StarFluid&  StarFluid::setFadeSpeed(float fadeSpeed) {
    this->fadeSpeed = fadeSpeed;
    return *this;
}

StarFluid&  StarFluid::setSolverIterations(int solverIterations) {
    this->solverIterations = solverIterations;
    return *this;
}

StarFluid& StarFluid::setWrap( bool bx, bool by ) {
    wrap_x = bx;
    wrap_y = by;
    return *this;
}

bool StarFluid::isInited() const {
    return _isInited;
}

StarFluid::~StarFluid() {
    destroy();
}

void StarFluid::destroy() {
    
    _isInited = false;
    if(custom_brush[0]) delete[] custom_brush[0];
    if(custom_brush[1]) delete[] custom_brush[1];
    if(custom_brush[2]) delete[] custom_brush[2];
    
    if(density)		delete []density;
    if(densityOld)	delete []densityOld;
    if(color)		delete []color;
    if(colorOld)	delete []colorOld;
    if(uv)		delete []uv;
    if(uvOld)	delete []uvOld;
}


void StarFluid::reset() {
    destroy();
    _isInited = true;
    
    density		= new float[_numCells];
    densityOld	= new float[_numCells];
    color		= new Color3[_numCells];
    colorOld	= new Color3[_numCells];
    uv    = new Vec2[_numCells];
    uvOld = new Vec2[_numCells];
    
    for ( int i =0;i<_numCells;i++ ) {
        density[i] = 0;
        densityOld[i] = 0;
        color[i].zero();
        colorOld[i].zero();
        uv[i].zero();
        uvOld[i].zero();
    }
}

// return total number of cells (_NX+2) * (_NY+2)
int StarFluid::getNumCells() const {
    return _numCells;
}

int StarFluid::getWidth() const {
    return _NX + 2;
}


int StarFluid::getHeight() const {
    return _NY + 2;
}

float StarFluid::getInvWidth() const {
    return invWidth;
}


float StarFluid::getInvHeight() const {
    return invHeight;
}

Vec2 StarFluid::getSize() {
    return Vec2(getWidth(), getHeight());
}

Vec2 StarFluid::getInvSize() {
    return Vec2(invWidth, invHeight);
}



StarFluid& StarFluid::setVisc(float newVisc) {
    viscocity = newVisc;
    return *this;
}

// returns current viscocity
float StarFluid::getVisc() const {
    return viscocity;
}


// returns average uniformity
float StarFluid::getUniformity() const {
    return _uniformity;
}

float StarFluid::getAvgSpeed() const {
    return _avgSpeed;
}


void StarFluid::update() {
    if (_isInited) {

        addSource(uv, uvOld);
        
        starSwap(uv, uvOld);
        
        diffuseUV( viscocity );

        project(uv, uvOld); //

        starSwap(uv, uvOld);
        
        advect2d(uv, uvOld); //
        
        project(uv, uvOld);
        
        addSource(color, colorOld);
        
        starSwap(color, colorOld);
        
        advectRGB(0, uv);
        
        fadeRGB();
        
    }
}

#define ZERO_THRESH		1e-9			// if value falls under this, set to zero (to avoid denormal slowdown)
//#define ZERO_THRESH		0			// if value falls under this, set to zero (to avoid denormal slowdown)
#define CHECK_ZERO(p)	if(fabsf(p)<ZERO_THRESH) p = 0


void StarFluid::fadeRGB() {
    
//    float holdAmount = 1 - _avgDensity * _avgDensity * fadeSpeed;	// this is how fast the density will decay depending on how full the screen currently is
    float holdAmount = 1 - fadeSpeed;
    
    _avgDensity = 0;
    _avgSpeed = 0;
    
    float totalDeviations = 0;
    float currentDeviation;
    Color3 tmp;
    _avgSpeed = 0;
    
    for (int i = _numCells-1; i >=0; --i)
    {
        // clear old values
        uvOld[i].zero();
        colorOld[i].zero();
        
        // calc avg speed
        _avgSpeed += uv[i].x * uv[i].x + uv[i].y * uv[i].y;
        
        // calc avg density
        tmp.r = starMin( 1.0f, color[i].r );
        tmp.g = starMin( 1.0f, color[i].g );
        tmp.b = starMin( 1.0f, color[i].b);
//        tmp.x=  color[i].x;
//        tmp.y = color[i].y;
//        tmp.z = color[i].z;
        //			tmp.a = min( 1.0f, color[i].a );
        
        //			float density = max(tmp.a, max( tmp.r, max( tmp.g, tmp.b ) ) );
        //			float density = max( tmp.r, max( tmp.g, tmp.b ) );
        float t = starMax( tmp.g, tmp.b);
        float density = starMax( tmp.r, t );
        _avgDensity += density;	// add it up
        
        // calc deviation (for _uniformity)
        currentDeviation = density - _avgDensity;
        totalDeviations += currentDeviation * currentDeviation;
        
        // fade out old
        color[i] = tmp * holdAmount;
        
        CHECK_ZERO(color[i].r);
        CHECK_ZERO(color[i].g);
        CHECK_ZERO(color[i].b);
        CHECK_ZERO(uv[i].x);
        CHECK_ZERO(uv[i].y);
    }
    _avgDensity *= _invNumCells;
    _avgSpeed *= _invNumCells;
    
    //println("%.3f\n", _avgDensity);
    _uniformity = 1.0f / (1 + totalDeviations * _invNumCells);		// 0: very wide distribution, 1: very uniform
}


void StarFluid::advect( int bound, float* d, const float* d0, const Vec2* duv) {
    int i0, j0, i1, j1;
    float x, y, s0, t0, s1, t1;
    int	index;
    
    const float dt0x = deltaT * _NX;
    const float dt0y = deltaT * _NY;
    
    for (int j = _NY; j > 0; --j)
    {
        for (int i = _NX; i > 0; --i)
        {
            index = FLUID_IX(i, j);
            x = i - dt0x * duv[index].x;
            y = j - dt0y * duv[index].y;
            
            if (x > _NX + 0.5) x = _NX + 0.5f;
            if (x < 0.5)     x = 0.5f;
            
            i0 = (int) x;
            i1 = i0 + 1;
            
            if (y > _NY + 0.5) y = _NY + 0.5f;
            if (y < 0.5)     y = 0.5f;
            
            j0 = (int) y;
            j1 = j0 + 1;
            
            s1 = x - i0;
            s0 = 1 - s1;
            t1 = y - j0;
            t0 = 1 - t1;
            
            d[index] = s0 * (t0 * d0[FLUID_IX(i0, j0)] + t1 * d0[FLUID_IX(i0, j1)])
            + s1 * (t0 * d0[FLUID_IX(i1, j0)] + t1 * d0[FLUID_IX(i1, j1)]);
            
        }
    }
    setBoundary(bound, d);
}

//          d    d0    du    dv
// advect(1, u, uOld, uOld, vOld);
// advect(2, v, vOld, uOld, vOld);
void StarFluid::advect2d( Vec2 *uv, const Vec2 *duv ) {
    int i0, j0, i1, j1;
    float s0, t0, s1, t1;
    int	index;
    
    const float dt0x = deltaT * _NX;
    const float dt0y = deltaT * _NY;
    
    for (int j = _NY; j > 0; --j)
    {
        for (int i = _NX; i > 0; --i)
        {
            index = FLUID_IX(i, j);
            float x = i - dt0x * duv[index].x;
            float y = j - dt0y * duv[index].y;
            
            if (x > _NX + 0.5) x = _NX + 0.5f;
            if (x < 0.5)     x = 0.5f;
            
            i0 = (int) x;
            i1 = i0 + 1;
            
            if (y > _NY + 0.5) y = _NY + 0.5f;
            if (y < 0.5)     y = 0.5f;
            
            j0 = (int) y;
            j1 = j0 + 1;
            
            s1 = x - i0;
            s0 = 1 - s1;
            t1 = y - j0;
            t0 = 1 - t1;
            
            uv[index].x = s0 * (t0 * duv[FLUID_IX(i0, j0)].x + t1 * duv[FLUID_IX(i0, j1)].x)
            + s1 * (t0 * duv[FLUID_IX(i1, j0)].x + t1 * duv[FLUID_IX(i1, j1)].x);
            uv[index].y = s0 * (t0 * duv[FLUID_IX(i0, j0)].y + t1 * duv[FLUID_IX(i0, j1)].y)
            + s1 * (t0 * duv[FLUID_IX(i1, j0)].y + t1 * duv[FLUID_IX(i1, j1)].y);
            
        }
    }
    setBoundary2d(1, uv);
    setBoundary2d(2, uv);
}

void StarFluid::advectRGB(int bound, const Vec2* duv) {
   	int i0, j0;
    float x, y, s0, t0, s1, t1, dt0x, dt0y;
    int	index;
    
    dt0x = deltaT * _NX;
    dt0y = deltaT * _NY;
    
    for (int j = _NY; j > 0; --j)
    {
        for (int i = _NX; i > 0; --i)
        {
            index = FLUID_IX(i, j);
            x = i - dt0x * duv[index].x;
            y = j - dt0y * duv[index].y;
            
            if (x > _NX + 0.5) x = _NX + 0.5f;
            if (x < 0.5)     x = 0.5f;
            
            i0 = (int) x;
            
            if (y > _NY + 0.5) y = _NY + 0.5f;
            if (y < 0.5)     y = 0.5f;
            
            j0 = (int) y;
            
            s1 = x - i0;
            s0 = 1 - s1;
            t1 = y - j0;
            t0 = 1 - t1;
            
            i0 = FLUID_IX(i0, j0);	//we don't need col/row index any more but index in 1 dimension
            j0 = i0 + (_NX + 2);
            color[index] = ( colorOld[i0] * t0 + colorOld[j0] * t1 ) * s0 + ( colorOld[i0+1] * t0 + colorOld[j0+1] * t1) * s1;
        }
    }
    setBoundaryRGB();
}


void StarFluid::diffuseUV( float diff )
{
    float a = deltaT * diff * _NX * _NY;
    linearSolverUV( a, 1.0 + 4 * a );
}

void StarFluid::project(Vec2* xy, Vec2* pDiv)
{
    float	 h;
    int		index;
    int		step_x = _NX + 2;
    
    h = - 0.5f / _NX;
    for (int j = _NY; j > 0; --j)
    {
        index = FLUID_IX(_NX, j);
        for (int i = _NX; i > 0; --i)
        {
            pDiv[index].x = h * ( xy[index+1].x - xy[index-1].x + xy[index+step_x].y - xy[index-step_x].y );
            pDiv[index].y = 0;
            --index;
        }
    }
    
    setBoundary02d( reinterpret_cast<Vec2*>( &pDiv[0].x ));
    setBoundary02d( reinterpret_cast<Vec2*>( &pDiv[0].y ));
    
    linearSolverProject( pDiv );
    
    float fx = 0.5f * _NX;
    float fy = 0.5f * _NY;	//maa	change it from _NX to _NY
    for (int j = _NY; j > 0; --j)
    {
        index = FLUID_IX(_NX, j);
        for (int i = _NX; i > 0; --i)
        {
            xy[index].x -= fx * (pDiv[index+1].x - pDiv[index-1].x);
            xy[index].y -= fy * (pDiv[index+step_x].x - pDiv[index-step_x].x);
            --index;
        }
    }
    
    setBoundary2d(1, xy);
    setBoundary2d(2, xy);
}


//	Gauss-Seidel relaxation
void StarFluid::linearSolver( int bound, float* __restrict x, const float* __restrict x0, float a, float c )
{
    int	step_x = _NX + 2;
    int index;
    c = 1. / c;
    for (int k = solverIterations; k > 0; --k)	// MEMO
    {
        for (int j = _NY; j > 0 ; --j)
        {
            index = FLUID_IX(_NX, j );
            for (int i = _NX; i > 0 ; --i)
            {
                x[index] = ( ( x[index-1] + x[index+1] + x[index - step_x] + x[index + step_x] ) * a + x0[index] ) * c;
                --index;
            }
        }
        setBoundary( bound, x );
    }
}

void StarFluid::linearSolverProject( Vec2* __restrict pdiv )
{
    int	step_x = _NX + 2;
    int index;
    for (int k = solverIterations; k > 0; --k) {
        for (int j = _NY; j > 0 ; --j) {
            index = FLUID_IX(_NX, j );
            float prev = pdiv[index+1].x;
            for (int i = _NX; i > 0 ; --i)
            {
                prev = ( pdiv[index-1].x + prev + pdiv[index - step_x].x + pdiv[index + step_x].x + pdiv[index].y ) * .25;
                pdiv[index].x = prev;
                --index;
            }
        }
        setBoundary02d( reinterpret_cast<Vec2*>( &pdiv[0].x ) );
    }
}

void StarFluid::linearSolverRGB( float a, float c )
{
//    NSLog(@"work?");
    int index1,index2,index3, index4, index;
    int	step_x = _NX + 2;
    c = 1. / c;
    for ( int k = solverIterations; k > 0; --k )	// MEMO
    {
        for (int j = _NY; j > 0 ; --j)
        {
            index = FLUID_IX(_NX, j );
            index1 = index - 1;		//FLUID_IX(i-1, j);
            index2 = index + 1;		//FLUID_IX(i+1, j);
            index3 = index - step_x;	//FLUID_IX(i, j-1);
            index4 = index + step_x;	//FLUID_IX(i, j+1);
            for (int i = _NX; i > 0 ; --i)
            {
                color[index] = ( ( color[index1] + color[index2]  +  color[index3] + color[index4] ) * a  +  colorOld[index] ) * c;
                --index;
                --index1;
                --index2;
                --index3;
                --index4;
            }
        }
        setBoundaryRGB();
    }
}

void StarFluid::linearSolverUV( float a, float c )
{
//    NSLog(@"work?");
    int index;
    int	step_x = _NX + 2;
    c = 1. / c;
    Vec2* __restrict localUV = uv;
    const Vec2* __restrict localOldUV = uvOld;
    
    for (int k = solverIterations; k > 0; --k)	
    {
        for (int j = _NY; j > 0 ; --j)
        {
            index = FLUID_IX(_NX, j );
            float prevU = localUV[index+1].x;
            float prevV = localUV[index+1].y;
            for (int i = _NX; i > 0 ; --i)
            {
                prevU = ( ( localUV[index-1].x + prevU + localUV[index - step_x].x + localUV[index + step_x].x ) * a  + localOldUV[index].x ) * c;
                prevV = ( ( localUV[index-1].y + prevV + localUV[index - step_x].y + localUV[index + step_x].y ) * a  + localOldUV[index].y ) * c;
                localUV[index].x = prevU;
                localUV[index].y = prevV;
                --index;
            }
        }
        setBoundary2d( 1, uv );
    }
}

void StarFluid::setBoundary(int bound, float* x)
{

    int dst1, dst2, src1, src2;
    int step = FLUID_IX(0, 1) - FLUID_IX(0, 0);
    
    dst1 = FLUID_IX(0, 1);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(_NX+1, 1 );
    src2 = FLUID_IX(_NX, 1);
    if( wrap_x )
        starSwap( src1, src2 );
    if( bound == 1 && !wrap_x )
        for (int i = _NY; i > 0; --i )
        {
            x[dst1] = -x[src1];	dst1 += step;	src1 += step;
            x[dst2] = -x[src2];	dst2 += step;	src2 += step;
        }
    else
        for (int i = _NY; i > 0; --i )
        {
            x[dst1] = x[src1];	dst1 += step;	src1 += step;
            x[dst2] = x[src2];	dst2 += step;	src2 += step;
        }
    
    dst1 = FLUID_IX(1, 0);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(1, _NY+1);
    src2 = FLUID_IX(1, _NY);
    if( wrap_y )
        starSwap( src1, src2 );
    if( bound == 2 && !wrap_y )
        for (int i = _NX; i > 0; --i )
        {
            x[dst1++] = -x[src1++];
            x[dst2++] = -x[src2++];
        }
    else
        for (int i = _NX; i > 0; --i )
        {
            x[dst1++] = x[src1++];
            x[dst2++] = x[src2++];
        }
    
    x[FLUID_IX(  0,   0)] = 0.5f * (x[FLUID_IX(1, 0  )] + x[FLUID_IX(  0, 1)]);
    x[FLUID_IX(  0, _NY+1)] = 0.5f * (x[FLUID_IX(1, _NY+1)] + x[FLUID_IX(  0, _NY)]);
    x[FLUID_IX(_NX+1,   0)] = 0.5f * (x[FLUID_IX(_NX, 0  )] + x[FLUID_IX(_NX+1, 1)]);
    x[FLUID_IX(_NX+1, _NY+1)] = 0.5f * (x[FLUID_IX(_NX, _NY+1)] + x[FLUID_IX(_NX+1, _NY)]);
}

void StarFluid::setBoundary02d(Vec2* x)
{
    int dst1, dst2, src1, src2;
    int step = FLUID_IX(0, 1) - FLUID_IX(0, 0);
    
    dst1 = FLUID_IX(0, 1);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(_NX+1, 1 );
    src2 = FLUID_IX(_NX, 1);
    if( wrap_x )
        starSwap( src1, src2 );
    for (int i = _NY; i > 0; --i )
    {
        x[dst1].x = x[src1].x;	dst1 += step;	src1 += step;
        x[dst2].x = x[src2].x;	dst2 += step;	src2 += step;
    }
    
    dst1 = FLUID_IX(1, 0);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(1, _NY+1);
    src2 = FLUID_IX(1, _NY);
    if( wrap_y )
        starSwap( src1, src2 );
    for (int i = _NX; i > 0; --i )
    {
        x[dst1++] = x[src1++];
        x[dst2++] = x[src2++];
    }
    
   
}

void StarFluid::setBoundary2d( int bound, Vec2 *xy )
{
    int dst1, dst2, src1, src2;
    int step = FLUID_IX(0, 1) - FLUID_IX(0, 0);
    
    dst1 = FLUID_IX(0, 1);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(_NX+1, 1 );
    src2 = FLUID_IX(_NX, 1);
    if( wrap_x )
        starSwap( src1, src2 );
    if( bound == 1 && !wrap_x )
        for (int i = _NY; i > 0; --i )
        {
            xy[dst1].x = -xy[src1].x;	dst1 += step;	src1 += step;	
            xy[dst2].x = -xy[src2].x;	dst2 += step;	src2 += step;	
        }
    else
        for (int i = _NY; i > 0; --i )
        {
            xy[dst1].x = xy[src1].x;	dst1 += step;	src1 += step;	
            xy[dst2].x = xy[src2].x;	dst2 += step;	src2 += step;	
        }
    
    dst1 = FLUID_IX(1, 0);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(1, _NY+1);
    src2 = FLUID_IX(1, _NY);
    if( wrap_y )
        starSwap( src1, src2 );
    if( bound == 2 && !wrap_y )
        for (int i = _NX; i > 0; --i )
        {
            xy[dst1++].y = -xy[src1++].y;	
            xy[dst2++].y = -xy[src2++].y;	
        }
    else
        for (int i = _NX; i > 0; --i )
        {
            xy[dst1++].y = xy[src1++].y;
            xy[dst2++].y = xy[src2++].y;	
        }
    
    xy[FLUID_IX(  0,   0)][bound-1] = (xy[FLUID_IX(1, 0  )][bound-1] + xy[FLUID_IX(  0, 1)][bound-1])*0.5f;
    xy[FLUID_IX(  0, _NY)][bound-1] = (xy[FLUID_IX(1, _NY)][bound-1] + xy[FLUID_IX(  0, _NY)][bound-1])*0.5f;
    xy[FLUID_IX(_NX,   0)][bound-1] =(xy[FLUID_IX(_NX, 0  )][bound-1] + xy[FLUID_IX(_NX, 1)][bound-1])*0.5f;
    xy[FLUID_IX(_NX, _NY)][bound-1] = (xy[FLUID_IX(_NX, _NY)][bound-1] + xy[FLUID_IX(_NX, _NY)][bound-1])*0.5f;
}

//#define CPY_RGB( d, s )		{	r[d] = r[s];	g[d] = g[s];	b[d] = b[s]; }
//#define CPY_RGB_NEG( d, s )	{	r[d] = -r[s];	g[d] = -g[s];	b[d] = -b[s]; }

void StarFluid::setBoundaryRGB()
{
    int dst1, dst2, src1, src2;
    int step = FLUID_IX(0, 1) - FLUID_IX(0, 0);
    
    dst1 = FLUID_IX(0, 1);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(_NX+1, 1 );
    src2 = FLUID_IX(_NX, 1);
    if( wrap_x )
        starSwap( src1, src2 );
    for (int i = _NY; i > 0; --i )
    {
        color[dst1] = color[src1];
        dst1 += step;
        src1 += step;	
        
        color[dst2] = color[src2];
        dst2 += step;
        src2 += step;	
    }
    
    dst1 = FLUID_IX(1, 0);
    src1 = FLUID_IX(1, 1);
    dst2 = FLUID_IX(1, _NY+1);
    src2 = FLUID_IX(1, _NY);
    if( wrap_y )
        starSwap( src1, src2 );
    for (int i = _NX; i > 0; --i )
    {
        color[dst1] = color[src1];
        ++dst1;
        ++src1;	
        
        color[dst2] = color[src2];
        ++dst2;
        ++src2;	
    }
}


void StarFluid::randomizeColor() {
    for (int i = getWidth()-1; i > 0; --i)
    {
        for (int j = getHeight()-1; j > 0; --j)
        {
//            int index = FLUID_IX(i, j);
//            color[index] = Vec3(Rand::randFloat(), Rand::randFloat(), Rand::randFloat());
//            density[index] = Rand::randFloat();
        }
    }
}
