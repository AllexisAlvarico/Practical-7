#include <Game.h>

bool updatable = false;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube"),
m_points
{
	{-1.0f, 1.0f, 1.0f},//1
	{1.0f, 1.0f, 1.0f}, //2
	{-1.0f, -1.0f, 1.0f }, // 3 
	{1.0f, -1.0f, 1.0f}, // 4
	{-1.0f, 1.0f, -1.0f}, // 5
	{1.0f, 1.0f, -1.0f}, // 6
	{-1.0f, -1.0f, -1.0f}, // 7
	{1.0f, -1.0f, -1.0f}, // 8

}
{
	index = glGenLists(1);
	m_angle = PI / 35; // 5 degrees
}

Game::~Game(){}

void Game::run()
{
	isRunning = true;


	sf::Event event;

	while (isRunning){
		initialize();
		std::cout << "Game running..." << std::endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 400.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f); 
		glVertex3f(m_points[1].m_x,m_points[1].m_y,m_points[1].m_z); //2
		glVertex3f(m_points[0].m_x, m_points[0].m_y, m_points[0].m_z); //1
		glVertex3f(m_points[2].m_x, m_points[2].m_y, m_points[2].m_z); // 3 

		glVertex3f(m_points[1].m_x, m_points[1].m_y, m_points[1].m_z); //2
		glVertex3f(m_points[3].m_x, m_points[3].m_y, m_points[3].m_z); // 4
		glVertex3f(m_points[2].m_x, m_points[2].m_y, m_points[2].m_z); // 3 


		// Top face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(m_points[0].m_x, m_points[0].m_y, m_points[0].m_z); //1
		glVertex3f(m_points[1].m_x, m_points[1].m_y, m_points[1].m_z); //2
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7

		glVertex3f(m_points[0].m_x, m_points[0].m_y, m_points[0].m_z); //1
		glVertex3f(m_points[4].m_x, m_points[4].m_y, m_points[4].m_z); // 5
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7


		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(m_points[5].m_x, m_points[5].m_y, m_points[5].m_z); // 6
		glVertex3f(m_points[4].m_x, m_points[4].m_y, m_points[4].m_z); // 5
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7

		glVertex3f(m_points[5].m_x, m_points[5].m_y, m_points[5].m_z); // 6
		glVertex3f(m_points[7].m_x, m_points[7].m_y, m_points[7].m_z); // 8
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7

		//bottom face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7
		glVertex3f(m_points[7].m_x, m_points[7].m_y, m_points[7].m_z); // 8
		glVertex3f(m_points[3].m_x, m_points[3].m_y, m_points[3].m_z); // 4

		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7
		glVertex3f(m_points[2].m_x, m_points[2].m_y, m_points[2].m_z); // 3 
		glVertex3f(m_points[3].m_x, m_points[3].m_y, m_points[3].m_z); // 4


		//left face
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(m_points[0].m_x, m_points[0].m_y, m_points[0].m_z); //1
		glVertex3f(m_points[4].m_x, m_points[4].m_y, m_points[4].m_z); // 5
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7

		glVertex3f(m_points[0].m_x, m_points[0].m_y, m_points[0].m_z); //1
		glVertex3f(m_points[2].m_x, m_points[2].m_y, m_points[2].m_z); // 3 
		glVertex3f(m_points[6].m_x, m_points[6].m_y, m_points[6].m_z); // 7

		// right face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(m_points[1].m_x, m_points[1].m_y, m_points[1].m_z); //2
		glVertex3f(m_points[5].m_x, m_points[5].m_y, m_points[5].m_z); // 6
		glVertex3f(m_points[7].m_x, m_points[7].m_y, m_points[7].m_z); // 8

		glVertex3f(m_points[1].m_x, m_points[1].m_y, m_points[1].m_z); //2
		glVertex3f(m_points[3].m_x, m_points[3].m_y, m_points[3].m_z); // 4
		glVertex3f(m_points[7].m_x, m_points[7].m_y, m_points[7].m_z); // 8



		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

		rotationAngle = 0.5f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			for (int i = 0; i < 8; i++)
			{
				m_points[i] = Matrix3f::rotationX(rotationAngle) * m_points[i];
			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			for (int i = 0; i < 8; i++)
			{
				m_points[i] = Matrix3f::translation(1.0f,1.0f) * m_points[i];
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			for (int i = 0; i < 8; i++)
			{
				m_points[i] = Matrix3f::scale(101.0f, 101.0f) * m_points[i];
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			for (int i = 0; i < 8; i++)
			{
				m_points[i] = Matrix3f::scale(99.0f, 99.0f) * m_points[i];
			}
		}

	
	std::cout << "Update up" << std::endl;
}

void Game::draw()
{
	std::cout << "Drawing" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::cout << "Drawing Cube " << std::endl;
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -8.0f);

	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	glCallList(1);

	window.display();

}

void Game::unload()
{
	std::cout << "Cleaning up" << std::endl;
}

