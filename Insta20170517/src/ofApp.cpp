#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp() {
	for (ofxBulletBox* tmp : this->obs) { delete tmp; }
	this->obs.clear();

	for (ofxBulletBox* tmp : this->boxes) { delete tmp; }
	this->boxes.clear();
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofEnableDepthTest();
	ofBackground(255);
	ofSetWindowTitle("picture break!");

	this->loop = false;

	this->world.setup();
	this->world.setGravity(ofVec3f(0.0, -1024.0, 0));

	ofxBulletBox* obstacle = new ofxBulletBox();
	obstacle->create(this->world.world, ofVec3f(0, -ofGetHeight(), -512), 0.0f, 512, 64, 2048);
	obstacle->setProperties(1.0, 0.3);
	obstacle->add();
	this->obs.push_back(obstacle);

	cv::Mat image = cv::imread("D:\\Samples\\Lenna.png");
	for (int x = 0; x < image.cols; x += 8) {
		for (int y = 0; y < image.rows; y += 8) {
			ofxBulletBox* box = new ofxBulletBox();
			box->create(this->world.world, ofVec3f(x - image.cols / 2, -y + ofGetHeight() / 2, -200), 1.0f, 8, 8, 8);
			box->setProperties(1.0, 0.3);
			box->add();
			this->boxes.push_back(box);

			int b = image.at<cv::Vec3b>(y, x)[0];
			int g = image.at<cv::Vec3b>(y, x)[1];
			int r = image.at<cv::Vec3b>(y, x)[2];
			this->boxes_colors.push_back(ofColor(r, g, b));
		}
	}

	this->light.setPosition(ofVec3f(512, 512, 512));
}

//--------------------------------------------------------------
void ofApp::update(){
	if (this->loop) {
		this->world.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	ofEnableLighting();
	this->light.enable();

	for (int i = 0; i < this->obs.size(); i++) {
		ofSetColor(128);
		this->obs[i]->draw();
	}

	for (int i = 0; i < this->boxes.size(); i++) {
		ofSetColor(this->boxes_colors[i]);
		this->boxes[i]->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 32) {
		this->loop = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
