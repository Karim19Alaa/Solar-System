

#define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 

#include <Renderer.h>
#include <Star.h>
#include <Director.h>
#include <StaticCamera.h>
#include <World.h>
#include <ViewPort.h>
#include <SpaceShip.h>
#include <SpaceFactory.h>


// Globals.
static int width, height; // Size of the OpenGL window.

static World *world;

static SpaceShip *spaceship;
static Renderer *spaceshipRenderer;
static ViewPort *spaceshipViewPort;

static Director *fixedCamera;
static Renderer *fixedRenderer;
static ViewPort *fixedViewPort;

SpaceFactory factory;

float globAmb[] = { 0.25, 0.25, 0.25, 1.0 };


// Routine to count the number of frames drawn every second.
void update(int value)
{
   world->tick();
   glutPostRedisplay();
   glutTimerFunc(17, update, 1);
}



// Initialization routine.
void setup(void)
{
	glEnable(GL_DEPTH_TEST);

	// Create the world
	world = new World();

	world->addObject(factory.create(SUN));

	world->addObject(factory.create(MERCURY));
	world->addObject(factory.create(VENUS));
	world->addObject(factory.create(EARTH));
	world->addObject(factory.create(MARS));
	world->addObject(factory.create(JUPYTER));
	world->addObject(factory.create(SATURNE));
	world->addObject(factory.create(URANUS));
	world->addObject(factory.create(NEPTUNE));

	//backgorund
	float cosmicColor[3] = {0.09, 0.08, 0.43};
	world->addObject(new Planet(400, 0, 0, 0, 0, 0, cosmicColor));

	//add spaceship
	spaceship = new SpaceShip(-100, 100, 45);
	world->addObject(spaceship);

	// Create the spaceship viewport and renderer
	spaceshipViewPort = new ViewPort(0, 0, width, height, *spaceship);
	spaceshipRenderer = new Renderer(world, spaceshipViewPort);

	// Create the fixed viewport and renderer
	double eye[3] = {0, 100, 0}, center[3]= {0, 0, 0}, up[3] = {0, 0, -1};
	fixedCamera = new StaticCamera (eye, center, up);
	fixedViewPort = new ViewPort(width * 2 / 3, 0, width / 3, height / 3, *fixedCamera);
	fixedRenderer = new Renderer(world, fixedViewPort);


	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);


	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutTimerFunc(0, update, 0); // Initial call of update().
}

// Drawing routine.
void drawScene(void)
{

   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	spaceshipRenderer->render();
	fixedRenderer->render();

  	glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	spaceshipViewPort->update(0, 0, w, h);
	fixedViewPort->update(2*w / 3, 0, w / 3, h / 3);

	// Pass the size of the OpenGL window.
	width = w;
	height = h;
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{

	// Compute next position.
	if (key == GLUT_KEY_LEFT) 	spaceship->steerLeft();
	if (key == GLUT_KEY_RIGHT)	spaceship->steerRight();
	if (key == GLUT_KEY_UP)
	{
		spaceship->throttle();
	}
	if (key == GLUT_KEY_DOWN)
	{
		spaceship->reverse();
	}
	glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Press the left/right arrow keys to turn the craft." << std::endl
		<< "Press the up/down arrow keys to move the craft." << std::endl;
}

// Main routine.
int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();

	delete world;
	delete spaceshipRenderer;
	delete fixedCamera;
	delete fixedRenderer;
	delete fixedViewPort;
	delete spaceshipViewPort;
	delete spaceship;

	return 0;
}