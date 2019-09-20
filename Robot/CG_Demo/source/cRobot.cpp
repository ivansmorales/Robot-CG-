#include "cRobot.h"

Robot::Robot()
{
	float sc[] = { 1,1,1 };
	float c1[] = { 0,0,0 };

	for (int i = 0; i < PARTS; i++) {
		parts[i] = new Block(c1, sc);
	}

	//Head
	parts[HEAD]->color[2] = 1;
	parts[HEAD]->size[0] = parts[HEAD]->size[1] = parts[HEAD]->size[2] = 0.5f;
	//Body
	parts[BODY]->color[0] = 1;
	//Neck
	parts[NECK]->color[0] = parts[NECK]->color[1] = parts[NECK]->color[2] = 1;
	parts[NECK]->size[0] = parts[NECK]->size[1] = parts[NECK]->size[2] = 0.3f;
	//Hips
	parts[HIPS]->color[0] = parts[HIPS]->color[1] = parts[HIPS]->color[2] = 1;
	parts[HIPS]->size[0] = parts[HIPS]->size[1] = parts[HIPS]->size[2] = 0.8f;
	//RSHOULDER
	parts[RSHOULDER]->color[0] = 1;
	parts[RSHOULDER]->size[0] = parts[RSHOULDER]->size[1] = parts[RSHOULDER]->size[2] = 0.4f;
	//RARM
	parts[RARM]->color[0] = parts[RARM]->color[1] = parts[RARM]->color[2] = 1;
	parts[RARM]->size[1] = parts[RARM]->size[2] = 0.4f;
	parts[RARM]->size[0] = 0.8f;
	//RHAND
	parts[RHAND]->color[2] = 1;
	parts[RHAND]->size[0] = parts[RHAND]->size[1] = parts[RHAND]->size[2] = 0.3f;
	//RLEG
	parts[RLEG]->color[0] = parts[RLEG]->color[1] = parts[RLEG]->color[2] = 1;
	parts[RLEG]->size[0] = parts[RLEG]->size[2] = 0.4f;
	parts[RLEG]->size[1] = 0.6f;
	//RANKLE
	parts[RANKLE]->color[2] = 1;
	parts[RANKLE]->size[0] = parts[RANKLE]->size[2] = 0.5f;
	parts[RANKLE]->size[1] = 0.7f;
	//RFOOT
	parts[RFOOT]->color[2] = 1;
	parts[RFOOT]->size[0] = parts[RFOOT]->size[2] = 0.5f;
	parts[RFOOT]->size[1] = 0.3f;
	//LSHOULDER
	parts[LSHOULDER]->color[0] = 1;
	parts[LSHOULDER]->size[0] = parts[LSHOULDER]->size[1] = parts[LSHOULDER]->size[2] = 0.4f;
	//LARM
	parts[LARM]->color[0] = parts[LARM]->color[1] = parts[LARM]->color[2] = 1;
	parts[LARM]->size[1] = parts[LARM]->size[2] = 0.4f;
	parts[LARM]->size[0] = 0.8f;
	//LHAND
	parts[LHAND]->color[2] = 1;
	parts[LHAND]->size[0] = parts[LHAND]->size[1] = parts[LHAND]->size[2] = 0.3f;
	//LLEG
	parts[LLEG]->color[0] = parts[LLEG]->color[1] = parts[LLEG]->color[2] = 1;
	parts[LLEG]->size[0] = parts[LLEG]->size[2] = 0.4f;
	parts[LLEG]->size[1] = 0.6f;
	//LANKLE
	parts[LANKLE]->color[2] = 1;
	parts[LANKLE]->size[0] = parts[LANKLE]->size[2] = 0.5f;
	parts[LANKLE]->size[1] = 0.7f;
	//LFOOT
	parts[LFOOT]->color[2] = 1;
	parts[LFOOT]->size[0] = parts[LFOOT]->size[2] = 0.5f;
	parts[LFOOT]->size[1] = 0.3f;
}

Robot::~Robot()
{
}

void Robot::draw() {
	parts[BODY]->draw();
	glPushMatrix(); {	
		glTranslatef(0, 0.5f, 0);
		parts[NECK]->draw();
		glPushMatrix(); {
			glTranslatef(0, 0.4f, 0);
			parts[HEAD]->draw();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix(); {	
		glTranslatef(0.7f, 0.32f, 0);
		parts[RSHOULDER]->draw(); 
		glPushMatrix(); {	
			glTranslatef(0.5f, 0.0f, 0);
			parts[RARM]->draw();
			glPushMatrix(); {
				glTranslatef(0.6f, 0.0f, 0);
				parts[RHAND]->draw();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix(); {	
		glTranslatef(-0.7f, 0.32f, 0);
		parts[LSHOULDER]->draw();
		glPushMatrix(); {	
			glTranslatef(-0.5f, 0.0f, 0);
			parts[LARM]->draw();
			glPushMatrix(); {
				glTranslatef(-0.6f, 0.0f, 0);
				parts[LHAND]->draw();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glTranslatef(0, -0.5f, 0);
	parts[HIPS]->draw();
	glPushMatrix(); { 
		glTranslatef(-0.3f, -0.70f, 0);
		parts[RLEG]->draw();
		glPushMatrix(); {
			glTranslatef(0, -0.70f, 0);
			parts[RANKLE]->draw();
			glPushMatrix(); {
				glTranslatef(0, -0.60f, 0);
				parts[RFOOT]->draw();
			}glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix(); {
		glTranslatef(0.3f, -0.70f, 0);
		parts[LLEG]->draw();
		glPushMatrix(); {
			glTranslatef(0, -0.70f, 0);
			parts[LANKLE]->draw();
			glPushMatrix(); {
				glTranslatef(0, -0.60f, 0);
				parts[LFOOT]->draw();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

}

void Robot::update() {
}