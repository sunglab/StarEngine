#ifndef STAR_FLUID_H
#define STAR_FLUID_H
#include "../star.h"
#include "../StarMain.h"
#include <math.h>
// do not change these values, you can override them using the solver methods
#define		FLUID_DEFAULT_NX					50
#define		FLUID_DEFAULT_NY					50
#define     FLUID_DEFAULT_DT					0.04f	//Maa	25fps
#define		FLUID_DEFAULT_VISC					0.0001f
#define     FLUID_DEFAULT_COLOR_DIFFUSION		0.0f
#define     FLUID_DEFAULT_FADESPEED				0.03f
#define		FLUID_DEFAULT_SOLVER_ITERATIONS		10

#define		FLUID_IX(i, j)		((i) + (_NX + 2)  *(j))
//#define SWAP(x0,x) {Vec3 *tmp=x0;x0=x;x=tmp;}
class FluidSolver {
public:
    FluidSolver();
    virtual ~FluidSolver();
    
    FluidSolver& setup(int NX = FLUID_DEFAULT_NX, int NY = FLUID_DEFAULT_NY);
    FluidSolver& setSize(int NX = FLUID_DEFAULT_NX, int NY = FLUID_DEFAULT_NY);
    
    // solve one step of the fluid solver
    void update();
    
    // clear all forces in fluid and reset
    void reset();
    
    // get fluid cell index for cell coordinates or normalized position
    inline int getIndexForCell(int i, int j) const;
    inline int getIndexForPos(const Vec2 &pos) const;
    
    
    // get color and/or vel at any point in the fluid.
    // pass pointers to Vec2 (for velocity) and Color (for color) and they get filled with the info
    // leave any pointer NULL if you don't want that info
    inline void getInfoAtIndex(int index, Vec2 *vel, Vec3 *color = NULL) const;
    inline void getInfoAtCell(int i, int j, Vec2 *vel, Vec3 *color = NULL) const;
    inline void getInfoAtPos(const Vec2 &pos, Vec2 *vel, Vec3 *color = NULL) const;
    
    
    // get just velocity
    inline Vec2 getVelocityAtIndex(int index) const;
    inline Vec2 getVelocityAtCell(int i, int j) const;
    inline Vec2 getVelocityAtPos(const Vec2 &pos) const;
    
    
    // get just color
    inline Vec3 getColorAtIndex(int index) const;
    inline Vec3 getColorAtCell(int i, int j) const;
    inline Vec3 getColorAtPos(const Vec2 &pos) const;
    
    
    // add force (at cell index, cell coordinates, or normalized position)
    inline void addForceAtIndex(int index, const Vec2 &force);
    inline void addForceAtCell(int i, int j, const Vec2 &force);
    inline void addForceAtPos(const Vec2 &pos, const Vec2 &force);
    
    
    // add color (at cell index, cell coordinates, or normalized position)
    inline void addColorAtIndex(int index, const Vec3 &color);
    inline void addColorAtCell(int i, int j, const Vec3 &color);
    inline void addColorAtPos(const Vec2 &pos, const Vec3 &color);
    
    
    // fill with random color at every cell
    void randomizeColor();
    
    // return number of cells and dimensions
    int getNumCells() const;
    int getWidth() const;
    int getHeight() const;
    float getInvWidth() const;
    float getInvHeight() const;
    Vec2 getSize();
    Vec2 getInvSize();
    
    bool isInited() const;
    
    // accessors for  viscocity, it will lerp to the target at lerpspeed
    FluidSolver& setVisc(float newVisc);
    float getVisc() const;
    
    // accessors for  color diffusion
    // if diff == 0, color diffusion is not performed
    // ** COLOR DIFFUSION IS SLOW!
    FluidSolver& setColorDiffusion( float diff);
    float				getColorDiffusion();
    
    FluidSolver& enableRGB(bool isRGB);
    FluidSolver& setDeltaT(float deltaT = FLUID_DEFAULT_DT);
    FluidSolver& setFadeSpeed(float fadeSpeed = FLUID_DEFAULT_FADESPEED);
    FluidSolver& setSolverIterations(int solverIterations = FLUID_DEFAULT_SOLVER_ITERATIONS);
    FluidSolver& enableVorticityConfinement(bool b);
    bool getVorticityConfinement();
    FluidSolver& setWrap( bool bx, bool by );
    
    // returns average density of fluid
    float getAvgDensity() const;
    
    // returns average _uniformity
    float getUniformity() const;
    
    // returns average speed of fluid
    float getAvgSpeed() const;
    
    // allocate an array large enough to hold information for u, v, r, g, OR b
    float* alloc()	{ return new float[_numCells];	}
    
    
    float	*density, *densityOld;		// used if not RGB
    Vec3	*color, *colorOld;			// used for RGB
    Vec2	*uv, *uvOld;
    
    float	*curl;
    
    bool	doRGB;				// for monochrome, update only density
    bool	doVorticityConfinement;
    int		solverIterations;
    
    float	colorDiffusion;
    float	viscocity;
    float	fadeSpeed;
    float	deltaT;
    bool	wrap_x;
    bool	wrap_y;
    
protected:
    
    float width;
    float height;
    float invWidth;
    float invHeight;
    
    int		_NX, _NY, _numCells;
    float	_invNX, _invNY, _invNumCells;
    bool	_isInited;
    float	*_tmp;
    
    float	_avgDensity;			// this will hold the average color of the last frame (how full it is)
    float	_uniformity;			// this will hold the _uniformity of the last frame (how uniform the color is);
    float	_avgSpeed;
    
    void	destroy();
    
    inline	float	calcCurl(int i, int j);
    void	vorticityConfinement(Vec2 *Fvc_xy);
    
    template<typename T>
    void	addSource(T *x, T *x0);
    
    void	advect(int b, float *d, const float *d0, const Vec2 *duv);
    void	advect2d( Vec2 *uv, const Vec2 *duv );
    void	advectRGB(int b, const Vec2 *duv);
    
    void	diffuse(int b, float *c, float *c0, float diff);
    void	diffuseRGB(int b, float diff);
    void	diffuseUV(float diff);
    
    void	project(Vec2 *xy, Vec2 *pDiv);
    void	linearSolver(int b, float *x, const float *x0, float a, float c);
    void	linearSolverProject( Vec2 *pdiv );
    void	linearSolverRGB( float a, float c);
    void	linearSolverUV(float a, float c);
    
    void	setBoundary(int b, float *x);
    void	setBoundary02d(Vec2* x);
    void	setBoundary2d(int b, Vec2 *xy );
    void	setBoundaryRGB();
    
    void	fadeDensity();
    void	fadeRGB();
   template<typename T>
   void SWAP(T &a, T& b)
    {
        T c = a;
        a = b;
        b = c;
    }
   template<typename T>
    T min(T a, T b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    template<typename T>
    T max(T a, T b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
//    template<typename T>
    float constrain(float c, float a, float b)
    {
        if(c<a)
            return a;
        else if(b<c)
            return b;
        else
            return c;
    }
public:
    void addToFluid( Vec2 pos, Vec2 vel, int id, bool addColor, bool addForce )
    {
        
//        srand(time(NULL));
        
        float speed = vel.x * vel.x  + vel.y * vel.y * (320.f/568.f) * (320.f/568.f);
        if( speed > 0 ) {
            pos.x = constrain( pos.x, 0.0f, 1.0f );
            pos.y = constrain( pos.y, 0.0f, 1.0f );
        
//            NSLog(@"%f %f %f %f", pos.x, pos.y, vel.x, vel.y);
            float colorMult = 50;
            float velocityMult = 100;
            if( addColor ) {
//                float temp = (rand()%100) *0.01;
                Vec3 drawColor(1.0,0.0,0.0);
                
                addColorAtPos( pos, drawColor*colorMult);//* colorMult);
            }
            
            if( addForce ) {
                addForceAtPos( pos, vel *velocityMult);
            }
        }
    }
};


//-------- get index
inline int FluidSolver::getIndexForCell(int i, int j) const {
//    i = constrain(i, 1, _NX);
//    j = constrain(j, 1, _NY);
    return FLUID_IX(i, j);
}

inline int FluidSolver::getIndexForPos(const Vec2 &pos) const {
    
//    NSLog(@"x cell : %d y cell : %d", (int)floor(pos.x * width),(int)floor(pos.y * height));
    return getIndexForCell((int)floor(pos.x * width), (int)floor(pos.y * height));
}



//-------- get info
inline	void FluidSolver::getInfoAtIndex(int index, Vec2 *vel, Vec3 *color) const {
    if(vel) *vel = getVelocityAtIndex(index);
    if(color) *color = getColorAtIndex(index);
}

inline void FluidSolver::getInfoAtCell(int i, int j, Vec2 *vel, Vec3 *color) const {
    getInfoAtIndex(getIndexForCell(i, j), vel, color);
}


inline void FluidSolver::getInfoAtPos(const Vec2 &pos, Vec2 *vel, Vec3 *color) const {
    getInfoAtIndex(getIndexForPos(pos), vel, color);
}


//-------- get velocity
inline Vec2 FluidSolver::getVelocityAtIndex(int index) const {
    return uv[index];
}

inline Vec2 FluidSolver::getVelocityAtCell(int i, int j) const {
    return getVelocityAtIndex(getIndexForCell(i, j));
}

inline Vec2 FluidSolver::getVelocityAtPos(const Vec2 &pos) const {
    return getVelocityAtIndex(getIndexForPos(pos));
}


//-------- get color
inline Vec3 FluidSolver::getColorAtIndex(int index) const {
    if(doRGB) {
        return Vec3(this->color[index].x, this->color[index].y, this->color[index].z);
    } else {
        return Vec3(density[index], density[index], density[index]);
    }
}

inline Vec3 FluidSolver::getColorAtCell(int i, int j) const {
    return getColorAtIndex(getIndexForCell(i, j));
}

inline Vec3 FluidSolver::getColorAtPos(const Vec2 &pos) const {
    return getColorAtIndex(getIndexForPos(pos));
}


//-------- add force
inline void FluidSolver::addForceAtIndex(int index, const Vec2 &force) {
    uv[index] += force;
}

inline void FluidSolver::addForceAtCell(int i, int j, const Vec2 &force) {
    addForceAtIndex(getIndexForCell(i, j), force);
}

inline void FluidSolver::addForceAtPos(const Vec2 &pos, const Vec2 &force) {
    addForceAtIndex(getIndexForPos(pos), force);
}


//-------- add color
inline void FluidSolver::addColorAtIndex(int index, const Vec3 &color) {
    if(doRGB) {
        colorOld[index] += Vec3(color.x, color.y, color.z);
//        NSLog(@"index : %d", index);
    } else {
        density[index] += color.x;
    }
}

inline void FluidSolver::addColorAtCell(int i, int j, const Vec3 &color) {
    addColorAtIndex(getIndexForCell(i, j), color);
}

inline void FluidSolver::addColorAtPos(const Vec2 &pos, const Vec3 &color) {
    addColorAtIndex(getIndexForPos(pos), color);
}

template<typename T>
void FluidSolver::addSource(T *x, T *x0) {
    for(int i = _numCells-1; i >=0; --i) {
        x[i] += x0[i] * deltaT;
    }
}
#endif
