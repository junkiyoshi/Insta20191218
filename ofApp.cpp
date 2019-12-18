#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(0);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofEnableDepthTest();

	ofxAssimpModelLoader model_loader;
	model_loader.loadModel("fuji.stl");
	this->mesh = model_loader.getMesh(0);

	for (auto& vertex : this->mesh.getVertices()) {

		vertex -= glm::vec3(75, 0, 75);
		auto value = ofMap(vertex.y, 186.56, 100, 255, 0);
		this->mesh.addColor(ofColor(value));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	this->mesh.drawVertices();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
