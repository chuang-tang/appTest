#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(54, 54, 54, 255);

	//old OF default is 96 - but this results in fonts looking larger than in other programs.
	ofTrueTypeFont::setGlobalDpi(72);

	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

	verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);

	verdana14A.loadFont("verdana.ttf", 14, false);
	verdana14A.setLineHeight(18.0f);
	verdana14A.setLetterSpacing(1.037);

	franklinBook14.loadFont("frabk.ttf", 14);
	franklinBook14.setLineHeight(18.0f);
	franklinBook14.setLetterSpacing(1.037);

	franklinBook14A.loadFont("frabk.ttf", 14, false);
	franklinBook14A.setLineHeight(18.0f);
	franklinBook14A.setLetterSpacing(1.037);

    username = "test rotation";
    text = "test text alpha";
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){



    ofSetColor(255,255,255);
    ofPushMatrix();
		ofRectangle bounds = verdana30.getStringBoundingBox(username, 155, 52);

		ofTranslate(155 + bounds.width/2, 232 + bounds.height / 2, 0);
		ofRotateY(ofGetElapsedTimef() * -30.0);

		verdana30.drawString(username, -bounds.width/2, bounds.height/2 );
	ofPopMatrix();

    alpha = ofGetElapsedTimef() * 0.2;
    ofEnableAlphaBlending();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f( 1.0, 1.0, 1.0, alpha );
    verdana30.drawString(text, 155, 292);
    ofDisableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
