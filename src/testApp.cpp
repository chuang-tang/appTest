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

    const char *strUsername = username.c_str();
    const char *strText = text.c_str();
    ofSetColor(255,255,255);
    ofTranslate(192, 252, 0);
    for(int i=0; i<username.length();i++)
    {
        strPerU.assign(1,strUsername[i]);
        ofRectangle bounds = verdana30.getStringBoundingBox(strPerU, 52, 52);
        ofTranslate(20, 0, 0);
        ofPushMatrix();
            ofRotateY(ofGetElapsedTimef() * -100.0);
            verdana30.drawString(strPerU, -bounds.width/2, bounds.height/2 );
        ofPopMatrix();
    }

    alpha = ofGetElapsedTimef() * 0.2;
    ofEnableAlphaBlending();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    for(int i=0; i<text.length();i++)
    {
        strPerT.assign(1,strText[i]);
        ofTranslate(20, 0, 0);
        glColor4f( 1.0, 1.0, 1.0, alpha-i*0.1 );
        verdana30.drawString(strPerT, 0, 0);
    }
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
