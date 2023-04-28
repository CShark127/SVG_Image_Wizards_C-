#include "ofApp.h"
#include <fstream>
#include <sstream>
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
	currColor = "green";

    svgString = readSvgFileAsString("Centura.svg");

	svgString = changeFillById(svgString, "Chamber_4_Background", currColor);
	svg.loadFromString(svgString);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	svg.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	if (currColor == "green") {
		currColor = "red";
	}
	else {
		currColor = "green";
	}

	svgString = changeFillById(svgString, "Chamber_4_Background", currColor);
	svg.loadFromString(svgString);
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

std::string ofApp::readSvgFileAsString(std::string path) {
	path = ofToDataPath(path);

	ofBuffer buffer = ofBufferFromFile(path);

	return buffer.getText();
}

std::string ofApp::changeFillById(std::string svgString, std::string id, std::string fillColor) {
	ofXml xml;

	xml.parse(svgString);

	ofXml::Search element = xml.find("//*[@id=\"" + id + "\"]");
	element[0].setAttribute("fill", fillColor);

	return xml.toString();
}