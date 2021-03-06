#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
#include "../include/twitcurl.h"

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void getStr();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont  franklinBook14;
		ofTrueTypeFont	verdana14;
		ofTrueTypeFont	verdana30;

		ofTrueTypeFont  franklinBook14A;
		ofTrueTypeFont	verdana14A;

        string username;
        string text;
        string strPerU;
        string strPerT;
        twitCurl twitterObj;
        string hashtag, result_num;
        string replyMsg;
		float alpha = 0;

};
