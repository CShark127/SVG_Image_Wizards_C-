#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include <fstream>
#include <sstream>
#include <string>

class ofApp : public ofBaseApp{

	public:
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

		std::string ofApp::readSvgFileAsString(std::string path);
		std::string ofApp::changeFillById(std::string svgString, std::string id, std::string fillColor);
		
	ofxSVG svg;
	std::string svgString;
	std::string currColor;
};
