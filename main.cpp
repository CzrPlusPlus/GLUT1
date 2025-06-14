/* Ceasar Moya-Cobian | Student ID: 300274872 | CSCI 173 | Assignment 1 - Sphere Move */
/* Can successfully detect collision but the physics of the collision is unrealistic */
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>

#include <math.h>
using namespace std;

bool WireFrame= false;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float sphereRadius = 0.6;   // Assignment says to use 1.3 but seems too big


// Variables for manipulating (x,y,z) values of all spheres as well as the colors
float sphere1X, sphere1Y, sphere1Z;
float color1R, color1G, color1B;
float distance1X, distance1Y, distance1Z;

float sphere2X, sphere2Y, sphere2Z;
float color2R, color2G, color2B;
float distance2X, distance2Y, distance2Z;

float sphere3X, sphere3Y, sphere3Z;
float color3R, color3G, color3B;
float distance3X, distance3Y, distance3Z;

float sphere4X, sphere4Y, sphere4Z;
float color4R, color4G, color4B;


// Variables to keep track of direction of sphere movement
int dir1X, dir1Y, dir1Z;
int dir2X, dir2Y, dir2Z;
int dir3X, dir3Y, dir3Z;
int dir4X, dir4Y, dir4Z;

float zoom;
float rotateCube;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
     double Ratio;

   if(width<=height)
            glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);
    else
          glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (50.0f,1,0.1f, 100.0f);
 }

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,zoom,0.0,0.0,0.0,0.0,1.0,0.0);    // using zoom variable here to increase/decrease z values through key presses

    if(WireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		//Draw Our Mesh In Wireframe Mesh
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		//Toggle WIRE FRAME

    // your code here

    glRotatef(rotateCube, 0, 1, 0);

    glPushMatrix();
    glColor3f(1, 1, 1);
    glutWireCube(8.0);
    glPopMatrix();

    // Sphere 1
    glPushMatrix();
    glTranslatef(sphere1X, sphere1Y, sphere1Z);
    glColor3f(color1R, color1G, color1B);
    glutSolidSphere(sphereRadius, 40, 40);
    glPopMatrix();

    // Sphere 2
    glPushMatrix();
    glTranslatef(sphere2X, sphere2Y, sphere2Z);
    glColor3f(color2R, color2G, color2B);
    glutSolidSphere(sphereRadius, 40, 40);
    glPopMatrix();

    // Sphere 3
    glPushMatrix();
    glTranslatef(sphere3X, sphere3Y, sphere3Z);
    glColor3f(color3R, color3G, color3B);
    glutSolidSphere(sphereRadius, 40, 40);
    glPopMatrix();

    // Sphere 4
    glPushMatrix();
    glTranslatef(sphere4X, sphere4Y, sphere4Z);
    glColor3f(color4R, color4G, color4B);
    glutSolidSphere(sphereRadius, 40, 40);
    glPopMatrix();

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }
}

void Specialkeys(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:   //  Zoom In
        zoom -= 0.5;
    break;

    case GLUT_KEY_DOWN: // Zoom Out
        zoom += 0.5;
    break;

    case GLUT_KEY_LEFT: // Rotate Left
        rotateCube += 5.0;
    break;

    case GLUT_KEY_RIGHT: // Rotate Right
        rotateCube -= 5.0;
    break;
   }
  glutPostRedisplay();
}

static void idle(void)
{
    /* S P H E R E 1 B E L O W */
    // Checking x-axis
    if(sphere1X + sphereRadius >= 4.0){         // collision with right side
        dir1X = -1;     // change direction
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere1X - sphereRadius <= -4.0){  // collision with left side
        dir1X = 1;      // change direction
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir1X == 1 ? sphere1X += 0.003 : sphere1X -= 0.003;

    // Checking y-axis
    if(sphere1Y + sphereRadius >= 4.0){         // collision with top side
        dir1Y = 1;     // change direction
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere1Y - sphereRadius <= -4.0){  // collision with bottom side
        dir1Y = -1;      // change direction
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir1Y == 1 ? sphere1Y -= 0.003 : sphere1Y += 0.003;

    // Checking z-axis
    if(sphere1Z + sphereRadius >= 4.0){         // collision with front side
        dir1Z = -1;     // change direction
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere1Z - sphereRadius <= -4.0){  // collision with back side
        dir1Z = 1;      // change direction
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir1Z == 1 ? sphere1Z += 0.003 : sphere1Z -= 0.003;

    // Checking for collision with other spheres
    // Sphere 1 & Sphere 2
    distance1X = sphere1X - sphere2X;
    distance1X = pow(distance1X, 2);
    distance1Y = sphere1Y - sphere2Y;
    distance1Y = pow(distance1Y, 2);
    distance1Z = sphere1Z - sphere2Z;
    distance1Z = pow(distance1Z, 2);
    if(sqrt(distance1X + distance1Y + distance1Z) < (sphereRadius * 2)){
        dir1X *= -1;
        dir1Y *= -1;
        dir1Z *= -1;
        dir2X *= -1;
        dir2Y *= -1;
        dir2Z *= -1;
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

    // Sphere 1 & Sphere 3
    distance1X = sphere1X - sphere3X;
    distance1X = pow(distance1X, 2);
    distance1Y = sphere1Y - sphere3Y;
    distance1Y = pow(distance1Y, 2);
    distance1Z = sphere1Z - sphere3Z;
    distance1Z = pow(distance1Z, 2);
    if(sqrt(distance1X + distance1Y + distance1Z) < (sphereRadius * 2)){
        dir1X *= -1;
        dir1Y *= -1;
        dir1Z *= -1;
        dir3X *= -1;
        dir3Y *= -1;
        dir3Z *= -1;
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

    // Sphere 1 & Sphere 4
    distance1X = sphere1X - sphere4X;
    distance1X = pow(distance1X, 2);
    distance1Y = sphere1Y - sphere4Y;
    distance1Y = pow(distance1Y, 2);
    distance1Z = sphere1Z - sphere4Z;
    distance1Z = pow(distance1Z, 2);
    if(sqrt(distance1X + distance1Y + distance1Z) < (sphereRadius * 2)){
        dir1X *= -1;
        dir1Y *= -1;
        dir1Z *= -1;
        dir4X *= -1;
        dir4Y *= -1;
        dir4Z *= -1;
        color1R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color1B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }


    /* S P H E R E 2 B E L O W */
    // Checking x-axis
    if(sphere2X + sphereRadius >= 4.0){         // collision with right side
        dir2X = 1;     // change direction
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere2X - sphereRadius <= -4.0){  // collision with left side
        dir2X = -1;      // change direction
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir2X == 1 ? sphere2X -= 0.003 : sphere2X += 0.003;

    // Checking y-axis
    if(sphere2Y + sphereRadius >= 4.0){         // collision with top side
        dir2Y = 1;     // change direction
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere2Y - sphereRadius <= -4.0){  // collision with bottom side
        dir2Y = -1;      // change direction
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir2Y == 1 ? sphere2Y -= 0.0033 : sphere2Y += 0.0033;

    // Checking z-axis
    if(sphere2Z + sphereRadius >= 4.0){         // collision with front side
        dir2Z = -1;     // change direction
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere2Z - sphereRadius <= -4.0){  // collision with back side
        dir2Z = 1;      // change direction
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir2Z == 1 ? sphere2Z += 0.003 : sphere2Z -= 0.003;

    // Checking for collision with other spheres
    // Sphere 2 & Sphere 3
    distance2X = sphere2X - sphere3X;
    distance2X = pow(distance2X, 2);
    distance2Y = sphere2Y - sphere3Y;
    distance2Y = pow(distance2Y, 2);
    distance2Z = sphere2Z - sphere3Z;
    distance2Z = pow(distance2Z, 2);
    if(sqrt(distance2X + distance2Y + distance2Z) < (sphereRadius * 2)){
        dir2X *= -1;
        dir2Y *= -1;
        dir2Z *= -1;
        dir3X *= -1;
        dir3Y *= -1;
        dir3Z *= -1;
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

    // Sphere 2 & Sphere 4
    distance2X = sphere2X - sphere4X;
    distance2X = pow(distance2X, 2);
    distance2Y = sphere2Y - sphere4Y;
    distance2Y = pow(distance2Y, 2);
    distance2Z = sphere2Z - sphere4Z;
    distance2Z = pow(distance2Z, 2);
    if(sqrt(distance2X + distance2Y + distance2Z) < (sphereRadius * 2)){
        dir2X *= -1;
        dir2Y *= -1;
        dir2Z *= -1;
        dir4X *= -1;
        dir4Y *= -1;
        dir4Z *= -1;
        color2R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color2B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

    /* S P H E R E 3 B E L O W */
    // Checking x-axis
    //sphere3X + sphereRadius >= 4.0 ? dir3X = -1 : sphere3X - sphereRadius <= -4.0 ? dir3X = 1 : NULL; // collision detection with cube
    if(sphere3X + sphereRadius >= 4.0){         // collision with right side
        dir3X = -1;     // change direction
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere3X - sphereRadius <= -4.0){  // collision with left side
        dir3X = 1;      // change direction
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir3X == 1 ? sphere3X += 0.0028 : sphere3X -= 0.0028;

    // Checking y-axis
    //sphere3Y + sphereRadius >= 4.0 ? dir3Y = -1 : sphere3Y - sphereRadius <= -4.0 ? dir3Y = 1 : NULL; // collision detection with cube
    if(sphere3Y + sphereRadius >= 4.0){         // collision with top side
        dir3Y = -1;     // change direction
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere3Y - sphereRadius <= -4.0){  // collision with bottom side
        dir3Y = 1;      // change direction
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir3Y == 1 ? sphere3Y += 0.003 : sphere3Y -= 0.003;

    // Checking z-axis
    //sphere3Z + sphereRadius >= 4.0 ? dir3Z = 1 : sphere3Z - sphereRadius <= -4.0 ? dir3Z = -1 : NULL; // collision detection with cube
    if(sphere3Z + sphereRadius >= 4.0){         // collision with top side
        dir3Z = 1;     // change direction
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere3Z - sphereRadius <= -4.0){  // collision with bottom side
        dir3Z = -1;      // change direction
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir3Z == 1 ? sphere3Z -= 0.0034 : sphere3Z += 0.0034;


    // Checking for collision with other spheres
    // Sphere 3 & Sphere 4
    distance3X = sphere3X - sphere4X;
    distance3X = pow(distance3X, 2);
    distance3Y = sphere3Y - sphere4Y;
    distance3Y = pow(distance3Y, 2);
    distance3Z = sphere3Z - sphere4Z;
    distance3Z = pow(distance3Z, 2);
    if(sqrt(distance3X + distance3Y + distance3Z) < (sphereRadius * 2)){
        dir3X *= -1;
        dir3Y *= -1;
        dir3Z *= -1;
        dir4X *= -1;
        dir4Y *= -1;
        dir4Z *= -1;
        color3R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color3B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

    /* S P H E R E 4 B E L O W */
    // Checking x-axis
    //sphere4X + sphereRadius >= 4.0 ? dir4X = 1 : sphere4X - sphereRadius <= -4.0 ? dir4X = -1 : NULL; // collision detection with cube
    if(sphere4X + sphereRadius >= 4.0){         // collision with right side
        dir4X = 1;     // change direction
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere4X - sphereRadius <= -4.0){  // collision with left side
        dir4X = -1;      // change direction
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir4X == 1 ? sphere4X -= 0.003 : sphere4X += 0.0027;

    // Checking y-axis
    //sphere4Y + sphereRadius >= 4.0 ? dir4Y = -1 : sphere4Y - sphereRadius <= -4.0 ? dir4Y = 1 : NULL; // collision detection with cube
    if(sphere4Y + sphereRadius >= 4.0){         // collision with top side
        dir4Y = -1;     // change direction
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere4Y - sphereRadius <= -4.0){  // collision with bottom side
        dir4Y = 1;      // change direction
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir4Y == 1 ? sphere4Y += 0.0031 : sphere4Y -= 0.0029;

    // Checking z-axis
    //sphere4Z + sphereRadius >= 4.0 ? dir4Z = 1 : sphere4Z - sphereRadius <= -4.0 ? dir4Z = -1 : NULL; // collision detection with cube
    if(sphere4Z + sphereRadius >= 4.0){         // collision with front side
        dir4Z = 1;     // change direction
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    else if (sphere4Z - sphereRadius <= -4.0){  // collision with back side
        dir4Z = -1;      // change direction
        color4R = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4G = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        color4B = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    dir4Z == 1 ? sphere4Z -= 0.0032 : sphere4Z += 0.0033;

    // Don't need to check collision here since all other spheres check for collision with sphere4

    glutPostRedisplay();
}

static void init(void)
{
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    sphere1X = -2.0;
    sphere1Y = -3.0;
    sphere1Z = 3.0;

    sphere2X = -2.0;
    sphere2Y = 3.0;
    sphere2Z = -0.5;

    sphere3X = 2.0;
    sphere3Y = -3.0;
    sphere3Z = -1.5;

    sphere4X = 2.0;
    sphere4Y = 3.0;
    sphere4Z = 2.5;

    zoom = 15.0;
    rotateCube = 0;

    dir1X = 1;
    dir1Y = 1;
    dir1Z = 1;

    dir2X = 1;
    dir2Y = 1;
    dir2Z = 1;

    dir3X = 1;
    dir3Y = 1;
    dir3Z = 1;

    dir4X = 1;
    dir4Y = 1;
    dir4Z = 1;

    color1R = 0;
    color1G = 0;
    color1B = 1;

    color2R = 0;
    color2G = 1;
    color2B = 0;

    color3R = 1;
    color3G = 0;
    color3B = 0;

    color4R = 1;
    color4G = 1;
    color4B = 0;

    distance1X = 0;
    distance1Y = 0;
    distance1Z = 0;
    distance2X = 0;
    distance2Y = 0;
    distance2Z = 0;
    distance3X = 0;
    distance3Y = 0;
    distance3Z = 0;

}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Assignment 1 - Sphere Move");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Specialkeys);

    glutIdleFunc(idle);
    glutMainLoop();

    return EXIT_SUCCESS;
}
