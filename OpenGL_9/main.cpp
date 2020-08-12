#include <stdlib.h>
#include <stdio.h>
#include <gl/glew.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <gl/glut.h>

//外部変数
//int alphaFlag = 0;
//GLclampf alphaRef = 0.5f;
//const char* imagefile = "star.png";//画像ファイル名
//GLuint texId;//テクスチャID
GLclampf fColor[4] = { 0.f,0.7f,1.f,1.f };//フォグの色
GLfloat zTrans = 0.f;

//各種コールバック関数

//ディスプレイ
void display()
{
	//バッファの初期化
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glEnable(GL_FOG);//有効化
	glColor3f(1.f, 1.f, 1.f);
	glPushMatrix();
	glTranslatef(0.f, 0.f, zTrans);
	glutWireTeapot(0.5);//描画
	glPopMatrix();
	glDisable(GL_FOG);//無効化

	//glBindTexture(GL_TEXTURE_2D, texId);//バインド
	//glColor3f(0.f, 1.f, 0.f);//緑色

	////フラグによる場合分け
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

	////デプステストの無効化
	//glDisable(GL_DEPTH_TEST);
	////ブレンドの有効化
	//glEnable(GL_BLEND);

	////正確には奥にあるものを先に描画
	//glPushMatrix();
	//glTranslatef(0.f, 0.f, -1.f);
	//glColor4f(0.f, 0.f, 1.f, 0.5f);//青
	//glRectf(-0.5, 0.5, 0.5, -0.5);
	//glPopMatrix();

	//glColor4f(1.f, 0.f, 0.f, 0.7f);//赤
	//glRectf(-0.5, 0.5, 0.5, -0.5);

	//glDisable(GL_BLEND);
	//glEnable(GL_DEPTH_TEST);
	//glColor3f(1.f, 1.f, 1.f);
	
	glutSwapBuffers();

}

//ウィンドウサイズを変更した際
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//ビューポートの設定

	glMatrixMode(GL_PROJECTION);//射影行列の設定
	glLoadIdentity();

	gluPerspective(30, (double)w / h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW); //モデルビュー行列の設定
	glLoadIdentity();
}


//キーボードイベント
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'a':
//		alphaFlag = ++alphaFlag % 2;//0か1をとる
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
//		glAlphaFunc(GL_LESS, alphaRef);//αテストの式
//		printf("AlphaRef = %f\n", alphaRef);
//		break;
//
//	case 'q':
//	case 'Q':
//	case '\033'://ESCキー
//		glDeleteTextures(1, &texId);//テクスチャの破棄
//		exit(0);
//		break;
//
//	default:
//		break;
//	}
//
//	glutPostRedisplay();//再描画
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

//その他各種設定
void otherInit()
{
	//背景のフォグの色に設定
	glClearColor(fColor[0], fColor[1], fColor[2], fColor[3]);
	glEnable(GL_DEPTH);
	//フォグの設定
	glFogfv(GL_FOG_COLOR, fColor);//色設定
	glFogf(GL_FOG_START, 5.f);//方程式の設定
	glFogf(GL_FOG_END, 20.f);
	glFogf(GL_FOG_MODE, GL_LINEAR);
	glHint(GL_FOG_HINT, GL_FASTEST);//ヒントを設定

	////カラーバッファの初期化
	//glClearColor(1.f, 1.f, 1.f, 1.f);
	//glEnable(GL_DEPTH_TEST);
	//glAlphaFunc(GL_LESS, alphaRef);//αテストの式
}


//拡張機能の確認
//void checkExtension()
//{
//	GLenum err = glewInit();
//	if (err != GLEW_OK)
//	{
//		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
//		exit(0);
//	}
//	//拡張機能の確認
//	if (glewIsSupported("GL_ARB_texture_non_power_of_two"))
//	{
//		puts("[GL_ARB_texture_non_power_of_two] : OK");
//	}
//	else
//	{
//		puts("[GL_ARB_texture_non_power_of_two] : BAD");
//	}
//}


//テクスチャ読み込み
//void LoadTexture()
//{
//	//画像読み込み
//	IplImage* imgA = cvLoadImage(imagefile, 0);
//	if (imgA == NULL) {
//		puts("Can`t load image");
//		exit(0);
//	}
//
//	//上下反転
//	cvFlip(imgA, imgA, 0);
//
//	glGenTextures(1, &texId);
//	glBindTexture(GL_TEXTURE_2D, texId);//バインド
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, imgA->width, imgA->height,
//		0, GL_ALPHA, GL_UNSIGNED_BYTE, imgA->imageData);
//
//	//メモリの開放
//	cvReleaseImage(&imgA);
//}

//メイン関数
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUTの初期化

	//Windowの作成
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //ディスプレイモード
	glutCreateWindow("Basic Fog");

	//checkExtension();//拡張機能の確認

	//コールバック関数登録
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);

	otherInit();
	//LoadTexture();

	glutMainLoop(); //メインループへ

	return 0;
}