#pragma once

#include "ofMain.h"
#include "ofxBullet.h"

// OpenCV
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_core310d.lib")
#pragma comment(lib,"opencv_highgui310d.lib")
#pragma comment(lib,"opencv_imgcodecs310d.lib")
#pragma comment(lib,"opencv_imgproc310d.lib")
#pragma comment(lib,"opencv_video310d.lib")
#pragma comment(lib,"opencv_videoio310d.lib")
#else
#pragma comment(lib,"opencv_core310.lib")
#pragma comment(lib,"opencv_highgui310.lib")
#pragma comment(lib,"opencv_imgcodecs310.lib")
#pragma comment(lib,"opencv_imgproc310.lib")
#pragma comment(lib,"opencv_video310.lib")
#pragma comment(lib,"opencv_videoio310.lib")
#endif

class ofApp : public ofBaseApp{

	public:
		~ofApp();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		bool loop;

		ofEasyCam cam;
		ofLight light;
		
		ofxBulletWorldRigid world;
		vector<ofxBulletBox*> obs;
		vector<ofxBulletBox*> boxes;
		vector<ofColor> boxes_colors;
};
