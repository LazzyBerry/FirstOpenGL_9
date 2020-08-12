#include <stdlib.h>
#include <stdio.h>
#include <gl/glew.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <gl/glut.h>

//�O���ϐ�
//int alphaFlag = 0;
//GLclampf alphaRef = 0.5f;
//const char* imagefile = "star.png";//�摜�t�@�C����
//GLuint texId;//�e�N�X�`��ID
GLclampf fColor[4] = { 0.f,0.7f,1.f,1.f };//�t�H�O�̐F
GLfloat zTrans = 0.f;

//�e��R�[���o�b�N�֐�

//�f�B�X�v���C
void display()
{
	//�o�b�t�@�̏�����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glEnable(GL_FOG);//�L����
	glColor3f(1.f, 1.f, 1.f);
	glPushMatrix();
	glTranslatef(0.f, 0.f, zTrans);
	glutWireTeapot(0.5);//�`��
	glPopMatrix();
	glDisable(GL_FOG);//������

	//glBindTexture(GL_TEXTURE_2D, texId);//�o�C���h
	//glColor3f(0.f, 1.f, 0.f);//�ΐF

	////�t���O�ɂ��ꍇ����
	//if (alphaFlag)
	//{
	//	glEnable(GL_ALPHA_TEST);
	//}
	//else {
	//	glDisable(GL_ALPHA_TEST);
	//}

	//glEnable(GL_TEXTURE_2D);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.f, 0.f); glVertex3f(-0.5f, -0.5f, 0.f);
	//glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, -0.5f, 0.f);
	//glTexCoord2f(1.f, 1.f); glVertex3f(0.5f, 0.5f, 0.f);
	//glTexCoord2f(0.f, 1.f); glVertex3f(-0.5f, 0.5f, 0.f);
	//glEnd();
	//glDisable(GL_ALPHA_TEST);

	////�f�v�X�e�X�g�̖�����
	//glDisable(GL_DEPTH_TEST);
	////�u�����h�̗L����
	//glEnable(GL_BLEND);

	////���m�ɂ͉��ɂ�����̂��ɕ`��
	//glPushMatrix();
	//glTranslatef(0.f, 0.f, -1.f);
	//glColor4f(0.f, 0.f, 1.f, 0.5f);//��
	//glRectf(-0.5, 0.5, 0.5, -0.5);
	//glPopMatrix();

	//glColor4f(1.f, 0.f, 0.f, 0.7f);//��
	//glRectf(-0.5, 0.5, 0.5, -0.5);

	//glDisable(GL_BLEND);
	//glEnable(GL_DEPTH_TEST);
	//glColor3f(1.f, 1.f, 1.f);
	
	glutSwapBuffers();

}

//�E�B���h�E�T�C�Y��ύX������
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//�r���[�|�[�g�̐ݒ�

	glMatrixMode(GL_PROJECTION);//�ˉe�s��̐ݒ�
	glLoadIdentity();

	gluPerspective(30, (double)w / h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW); //���f���r���[�s��̐ݒ�
	glLoadIdentity();
}


//�L�[�{�[�h�C�x���g
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'a':
//		alphaFlag = ++alphaFlag % 2;//0��1���Ƃ�
//		if (alphaFlag) {
//			puts("[ALPHA TEST]: ON");
//		}
//		else {
//			puts("[ALPHA TEST]: OFF");
//		}
//		break;
//
//	case 'r':
//		alphaRef += 0.05f;
//		if (alphaRef > 1.f) {
//			alphaRef = 0.f;
//		}
//		glAlphaFunc(GL_LESS, alphaRef);//���e�X�g�̎�
//		printf("AlphaRef = %f\n", alphaRef);
//		break;
//
//	case 'q':
//	case 'Q':
//	case '\033'://ESC�L�[
//		glDeleteTextures(1, &texId);//�e�N�X�`���̔j��
//		exit(0);
//		break;
//
//	default:
//		break;
//	}
//
//	glutPostRedisplay();//�ĕ`��
//}

void specialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		zTrans -= 0.2f;
		break;
	case GLUT_KEY_DOWN:
		zTrans += 0.2f;
		break;
	case GLUT_KEY_F1:
		zTrans = 0.f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

//���̑��e��ݒ�
void otherInit()
{
	//�w�i�̃t�H�O�̐F�ɐݒ�
	glClearColor(fColor[0], fColor[1], fColor[2], fColor[3]);
	glEnable(GL_DEPTH);
	//�t�H�O�̐ݒ�
	glFogfv(GL_FOG_COLOR, fColor);//�F�ݒ�
	glFogf(GL_FOG_START, 5.f);//�������̐ݒ�
	glFogf(GL_FOG_END, 20.f);
	glFogf(GL_FOG_MODE, GL_LINEAR);
	glHint(GL_FOG_HINT, GL_FASTEST);//�q���g��ݒ�

	////�J���[�o�b�t�@�̏�����
	//glClearColor(1.f, 1.f, 1.f, 1.f);
	//glEnable(GL_DEPTH_TEST);
	//glAlphaFunc(GL_LESS, alphaRef);//���e�X�g�̎�
}


//�g���@�\�̊m�F
//void checkExtension()
//{
//	GLenum err = glewInit();
//	if (err != GLEW_OK)
//	{
//		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
//		exit(0);
//	}
//	//�g���@�\�̊m�F
//	if (glewIsSupported("GL_ARB_texture_non_power_of_two"))
//	{
//		puts("[GL_ARB_texture_non_power_of_two] : OK");
//	}
//	else
//	{
//		puts("[GL_ARB_texture_non_power_of_two] : BAD");
//	}
//}


//�e�N�X�`���ǂݍ���
//void LoadTexture()
//{
//	//�摜�ǂݍ���
//	IplImage* imgA = cvLoadImage(imagefile, 0);
//	if (imgA == NULL) {
//		puts("Can`t load image");
//		exit(0);
//	}
//
//	//�㉺���]
//	cvFlip(imgA, imgA, 0);
//
//	glGenTextures(1, &texId);
//	glBindTexture(GL_TEXTURE_2D, texId);//�o�C���h
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, imgA->width, imgA->height,
//		0, GL_ALPHA, GL_UNSIGNED_BYTE, imgA->imageData);
//
//	//�������̊J��
//	cvReleaseImage(&imgA);
//}

//���C���֐�
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUT�̏�����

	//Window�̍쐬
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //�f�B�X�v���C���[�h
	glutCreateWindow("Basic Fog");

	//checkExtension();//�g���@�\�̊m�F

	//�R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);

	otherInit();
	//LoadTexture();

	glutMainLoop(); //���C�����[�v��

	return 0;
}