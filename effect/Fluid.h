#ifndef STAR_FLUID_H
#define STAR_FLUID_H
#include "../star.h"
#include "../StarMain.h"
#include "../tool/StarUtil.h"
#include <math.h>

// do not change these values, you can override them using the solver methods
#define		FLUID_DEFAULT_NX					50
#define		FLUID_DEFAULT_NY					50
#define     FLUID_DEFAULT_DT					0.04f	//Maa	25fps
#define		FLUID_DEFAULT_VISC					0.0001f
//#define     FLUID_DEFAULT_COLOR_DIFFUSION		0.1f
#define     FLUID_DEFAULT_FADESPEED				0.003f
#define		FLUID_DEFAULT_SOLVER_ITERATIONS		10  // why 10 ??
#define		FLUID_IX(i, j)		((i) + (_NX + 2)  *(j))

class StarFluid {
public:
    StarFluid();
    virtual ~StarFluid();
    
    StarFluid& setup(int NX = FLUID_DEFAULT_NX, int NY = FLUID_DEFAULT_NY);
    StarFluid& setSize(int NX = FLUID_DEFAULT_NX, int NY = FLUID_DEFAULT_NY);
    
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
    inline void getInfoAtIndex(int index, Vec2 *vel, Color3 *color = NULL) const;
    inline void getInfoAtCell(int i, int j, Vec2 *vel, Color3 *color = NULL) const;
    inline void getInfoAtPos(const Vec2 &pos, Vec2 *vel, Color3 *color = NULL) const;
    
    
    // get just velocity
    inline Vec2 getVelocityAtIndex(int index) const;
    inline Vec2 getVelocityAtCell(int i, int j) const;
    inline Vec2 getVelocityAtPos(const Vec2 &pos) const;
    
    
    // get just color
    inline Color3 getColorAtIndex(int index) const;
    inline Color3 getColorAtCell(int i, int j) const;
    inline Color3 getColorAtPos(const Vec2 &pos) const;
    
    
    // add force (at cell index, cell coordinates, or normalized position)
    inline void addForceAtIndex(int index, const Vec2 &force);
    inline void addForceAtCell(int i, int j, const Vec2 &force);
    inline void addForceAtPos(const Vec2 &pos, const Vec2 &force);
    
    
    // add color (at cell index, cell coordinates, or normalized position)
    inline void addColorAtIndex(int index, const Color3 &color);
    inline void addColorAtCell(int i, int j, const Color3 &color);
    inline void addColorAtPos(const Vec2 &pos, const Color3 &color);
    
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
    StarFluid& setVisc(float newVisc);
    float getVisc() const;
    
    float *custom_brush[3];
    unsigned int custom_brush_radius[3];
    
    void setBrush(unsigned int default_radius)
    {
        
        default_radius = starConstrain(default_radius, (unsigned int)5, (unsigned int)9);
        custom_brush_radius[0] = default_radius-2;
        custom_brush_radius[1] = default_radius;
        custom_brush_radius[2] = default_radius+2;
        
        custom_brush[0]  = new float[custom_brush_radius[0]*custom_brush_radius[0]];
        custom_brush[1]  = new float[custom_brush_radius[1]*custom_brush_radius[1]];
        custom_brush[2]  = new float[custom_brush_radius[2]*custom_brush_radius[2]];
        
        printf("\n ");
        for(int a=0;a<3;a++)
        {
        int l_radius = custom_brush_radius[a];
        int start = floorl((l_radius)/2.);
        for(int i=0;i<(l_radius);i++)
            for(int j=0;j<(l_radius);j++)
            {
               
float multi = ((start-abs(start-i))*(1./(2*start))+ (start-abs(start-j))*(1./(2*start)));
//                if (l_radius==3&&multi==0)
//                    multi = 0.25;
//                if (l_radius==3&&multi==1)
//                    multi = 0.75;
//               if(a==1)
//                   printf("%f ",multi*multi);
//                float multi2 = multi*(multi*2.);
//                starConstrain(multi2,(float)0.0,(float)1.0);
                custom_brush[a][i*l_radius+j] = multi*multi;
            }
        }
    }
    // accessors for  color diffusion
    // if diff == 0, color diffusion is not performed
    // ** COLOR DIFFUSION IS SLOW!
//    StarFluid& setColorDiffusion( float diff);
//    float				getColorDiffusion();
    
    StarFluid& setDeltaT(float deltaT = FLUID_DEFAULT_DT);
    StarFluid& setFadeSpeed(float fadeSpeed = FLUID_DEFAULT_FADESPEED);
    StarFluid& setSolverIterations(int solverIterations = FLUID_DEFAULT_SOLVER_ITERATIONS);
//    StarFluid& enableVorticityConfinement(bool b);
//    bool getVorticityConfinement();
    StarFluid& setWrap( bool bx, bool by );
    // returns average density of fluid
//    float getAvgDensity() const;
    
    // returns average _uniformity
    float getUniformity() const;
    
    // returns average speed of fluid
    float getAvgSpeed() const;
    
    // allocate an array large enough to hold information for u, v, r, g, OR b
    float* alloc()	{ return new float[_numCells];	}
    
    
    float	*density, *densityOld;		// used if not RGB
    Color3	*color, *colorOld;			// used for RGB
    Vec2	*uv, *uvOld;
    
    int		solverIterations;
    
    float	viscocity;
    float	fadeSpeed;
    float	deltaT;
    bool	wrap_x;
    bool	wrap_y;
    
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
public:
    void addToFluid( Vec2 pos, Vec2 vel, int id, bool addColor, bool addForce,Color3& colors,int a,float div)
    {

            pos.x = starConstrain(pos.x, 0.0f, 1.0f);
            pos.y = starConstrain(pos.y, 0.0f, 1.0f);
//            r = starConstrain(a, 0, 2);
            int index = getIndexForPos(pos);
        if(addForce)
        {
            
//                        vel.x = starConstrain(vel.x,-0.01f,0.01f);
//                        vel.y = starConstrain(vel.y,-0.01f,0.01f);
//            printf("power %f",vel.length());
            
//            vel.x = starConstrain(vel.x,-0.005f,0.005f);
//            vel.y = starConstrain(vel.y,-0.005f,0.005f);
            
            vel.x = starConstrain(vel.x,-0.003f,0.003f);
            vel.y = starConstrain(vel.y,-0.003f,0.003f);
            addForceAtIndex(index, vel);
        }
        
            if(addColor)
            {
                int radius = custom_brush_radius[a];//13.0;
//                int radius = 7.0;//test
                int texwidth = (_NX+2);
                int start = floorl(radius/2.);
//                        static bool once=true;
//                if(once)
//                {
////                    printf("\n 0------00-----00------ %d\n", 8*(custom_brush_radius[2])+8);
//                    for(int i=0;i<radius;i++)
//                        for(int j=0;j<radius;j++)
//                        {
//                            printf(" %d ",i*(custom_brush_radius[a])+j);
//                            float multi = custom_brush[a][i*(custom_brush_radius[a])+j];
//                            printf(" %f ", multi);
//
//                             multi = (start-abs(start-i))*(1./(2*start))+ (start-abs(start-j))*(1./(2*start));
//                            printf(" %f \n", multi);
//                            //                            if(j==radius-1)
//                            //                                printf("\n");
//                        }
//                    once = false;
//                }
                for(int i=0;i<radius;i++)
                    for(int j=0;j<radius;j++)
                    {
                        float multi = custom_brush[a][i*(custom_brush_radius[a])+j];
//                float multi = (start-abs(start-i))*(1./(2*start))+ (start-abs(start-j))*(1./(2*start));
                        addColorAtIndex(index-texwidth*start-start+i+(texwidth*j), colors*multi*div);//0.005
                    }
        
            }
        }
};


//get index
inline int StarFluid::getIndexForCell(int i, int j) const {
    i = starConstrain(i, 1, _NX);
    j = starConstrain(j, 1, _NY);
    return FLUID_IX(i, j);
}

inline int StarFluid::getIndexForPos(const Vec2 &pos) const {
    
//    NSLog(@"x cell : %d y cell : %d", (int)floor(pos.x * width),(int)floor(pos.y * height));
    return getIndexForCell((int)floor(pos.x * width), (int)floor(pos.y * height));
}



//get info
inline	void StarFluid::getInfoAtIndex(int index, Vec2 *vel, Color3 *color) const {
    if(vel) *vel = getVelocityAtIndex(index);
    if(color) *color = getColorAtIndex(index);
}

inline void StarFluid::getInfoAtCell(int i, int j, Vec2 *vel, Color3 *color) const {
    getInfoAtIndex(getIndexForCell(i, j), vel, color);
}


inline void StarFluid::getInfoAtPos(const Vec2 &pos, Vec2 *vel, Color3 *color) const {
    getInfoAtIndex(getIndexForPos(pos), vel, color);
}


//get velocity
inline Vec2 StarFluid::getVelocityAtIndex(int index) const {
    return uv[index];
}

inline Vec2 StarFluid::getVelocityAtCell(int i, int j) const {
    return getVelocityAtIndex(getIndexForCell(i, j));
}

inline Vec2 StarFluid::getVelocityAtPos(const Vec2 &pos) const {
    return getVelocityAtIndex(getIndexForPos(pos));
}


//-------- get color
inline Color3 StarFluid::getColorAtIndex(int index) const {
        return Color3(this->color[index].r, this->color[index].g, this->color[index].b);
}

inline Color3 StarFluid::getColorAtCell(int i, int j) const {
    return getColorAtIndex(getIndexForCell(i, j));
}

inline Color3 StarFluid::getColorAtPos(const Vec2 &pos) const {
    return getColorAtIndex(getIndexForPos(pos));
}


//add force
inline void StarFluid::addForceAtIndex(int index, const Vec2 &force) {
//    starConstrain(force.x, 0.0, 1.0);
//    starConstrain(force.y, 0.0, 1.0);
    uv[index] += force;
//    uvOld[index] += force;
}

inline void StarFluid::addForceAtCell(int i, int j, const Vec2 &force) {
    addForceAtIndex(getIndexForCell(i, j), force);
}

inline void StarFluid::addForceAtPos(const Vec2 &pos, const Vec2 &force) {
    addForceAtIndex(getIndexForPos(pos), force);
}


//add color
inline void StarFluid::addColorAtIndex(int index, const Color3 &color) {
        if(index>=0&&index<_numCells)
        colorOld[index] += Color3(color.r, color.g, color.b);
}
inline void StarFluid::addColorAtCell(int i, int j, const Color3 &color) {
    addColorAtIndex(getIndexForCell(i, j), color);
}

inline void StarFluid::addColorAtPos(const Vec2 &pos, const Color3 &color) {
    addColorAtIndex(getIndexForPos(pos), color);
}

template<typename T>
void StarFluid::addSource(T *x, T *x0) {
    for(int i = _numCells-1; i >=0; --i) {
        x[i] += x0[i] * deltaT;
    }
}
#endif
