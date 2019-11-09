#include "..\header\cBlock.h"

Block::Block(float *c, float *s)
{
	color[0] = c[0];
	color[1] = c[1];
	color[2] = c[2];
	size[0] = s[0];
	size[1] = s[1];
	size[2] = s[2];
}

Block::~Block()
{
}

void Block::draw() {
	glPushMatrix(); {
		glColor3f(color[0], color[1], color[2]);
		glScalef(size[0], size[1], size[2]);
		glutSolidCube(1);
	}
	glPopMatrix();
}
void Block::update() {
}
