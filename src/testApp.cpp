#include "testApp.h"

const int TextWidth = 10;
const int TextHeight = 15;
//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(54, 54, 54, 255);

	// Set fonts of display
	ofTrueTypeFont::setGlobalDpi(72);

	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

	verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);

    // OAuth flow begins
    // Set OAuth related params. These are got by registering your app at twitter.com
    twitterObj.getOAuth().setConsumerKey( string( "C65GavtfFCZApq7kYz4w" ) );
    twitterObj.getOAuth().setConsumerSecret( string( "JH7KS1B0zKldhkay4mN9yA5DvVNlQYOhAYAYqcwNc14" ) );
    string myOAuthAccessTokenKey("371718714-whlxhOIrUy6I4L5DyGlujIeutr9ufkO9IBP9crql");
    string myOAuthAccessTokenSecret("ul1FWGsnJdMzGZncw9kG91sGwA07nIgtrERfzix3bb0L0");

    printf( "\nUsing:\nKey: %s\nSecret: %s\n\n", myOAuthAccessTokenKey.c_str(), myOAuthAccessTokenSecret.c_str() );

    twitterObj.getOAuth().setOAuthTokenKey( myOAuthAccessTokenKey );
    twitterObj.getOAuth().setOAuthTokenSecret( myOAuthAccessTokenSecret );

    /* Search a string */
    hashtag="England";
    result_num="1";
    replyMsg = "";
    if( twitterObj.search( hashtag, result_num) )
    {
        twitterObj.getLastWebResponse( replyMsg );
        printf( "\ntwitterClient:: twitCurl::search web response:\n%s\n", replyMsg.c_str() );
    }
    else
    {
        twitterObj.getLastCurlError( replyMsg );
        printf( "\ntwitterClient:: twitCurl::search error:\n%s\n", replyMsg.c_str() );
    }

    string text_symbol("\"text\"");
    string text_end_symbol("\"source\"");

    string name_symbol("\"name\"");
    string name_end_symbol("\"screen");

    int text_start = replyMsg.find(text_symbol) + text_symbol.length()+ 2;
    int text_end = replyMsg.find(text_end_symbol) - 2;

    int name_start = replyMsg.find(name_symbol) + name_symbol.length() + 2;
    int name_end = replyMsg.find(name_end_symbol) - 2;

    username.assign(replyMsg, name_start, name_end - name_start);
    text.assign(replyMsg, text_start, text_end - text_start);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    const char *strUsername = username.c_str();
    const char *strText = text.c_str();
    ofSetColor(255,255,255);
    ofTranslate(100, 252, 0);
    for(int i=0; i<username.length();i++)
    {
        ofTranslate(20, 0, 0);
        strPerU.assign(1,strUsername[i]);
        ofRectangle bounds = verdana30.getStringBoundingBox(strPerU, 34, 34);
        ofPushMatrix();
            if((ofGetElapsedTimef()-i) * -100 < -360)
                ofRotateY(0);
            else
                ofRotateY((ofGetElapsedTimef()-i) * -100.0);
            verdana30.drawString(strPerU, -bounds.width/2, bounds.height/2 );
        ofPopMatrix();
    }

    int lineNum = 0;
    int letterNumPerLine = 0;
    bool changeLine = 0;
    alpha = ofGetElapsedTimef() * 0.7;
    ofEnableAlphaBlending();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    ofTranslate(50, 0, 0);
    for(int i=0,j=0; i<text.length();i++,j++)
    {
        strPerT.assign(1,strText[i]);
        if(strPerT == "\\")
        {
            i++;
            strPerT.assign(1,strText[i]);
        }

        glColor4f( 1.0, 1.0, 1.0, alpha-j*0.1 );
        verdana14.drawString(strPerT, letterNumPerLine * 10, lineNum * 20);
        letterNumPerLine++;
        if(letterNumPerLine%30 == 0)
            changeLine = 1;
        if(strPerT == " " && changeLine)
        {
            lineNum++;
            letterNumPerLine = 0;
            changeLine = 0;
        }
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
