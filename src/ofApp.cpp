#include "ofApp.h"

agent Agents[MAX_AGENTS];
int curAgent = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024,768);
    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second
    ofBackground(0);
    
    for (curAgent; curAgent < MAX_AGENTS; curAgent++) {  // only enable if we disable mouse gravity
        Agents[curAgent].start(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i < MAX_AGENTS; i++) {
        Agents[i].update(Agents);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int alpha = 150;
    
    ofColor aqua(0, 252, 255, alpha);
    ofColor purple(198, 0, 205, alpha);
    ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));  // linear interpolation between colors color
    
    for (int i=0; i < MAX_AGENTS; i++) {
        ofSetColor(inbetween);
        Agents[i].draw();
    }
    drawwave();
}

void ofApp::drawwave(){
    
    ofTranslate(mouseX,mouseY); // move initital drawing postion to the center of the screen
    int circle_resolution=1600; // amount of points circle is made of, more points - better quality, but could decrease perfomance
    int radius=200;
    int smoothing_amount=50;
    
    ofPolyline circle_sin;
    
    
    int wave_height=radius*0.1;
    int anim_shape=16;
    float sine_pct=0.5; // setting in percantage how big is the part
    
    float speed_increment=ofGetElapsedTimef();
    
    int line_w=2;
    int radius_cos=radius+line_w-5; // let's make it little less then line width, so circles will overlap each other
    int radius_un_cos=radius+(line_w-5)*2;
    for(int i=0; i<circle_resolution; i++)
    {
        
        float angle=TWO_PI/circle_resolution*i;
        float raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
        float x=cos(angle+speed_increment)*radius;
        float y=sin(angle+speed_increment)*radius;
        
        // drawing sine wave only on a part of the circle
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
        }
        circle_sin.addVertex(ofPoint(x,y));
        
        
        raidus_addon=wave_height*cos((angle+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_cos);
        y=sin(angle+speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_cos+raidus_addon);
        }
        
    }
    
    ofSetLineWidth(line_w);
    
//    ofColor clr=ofColor::fromHex(0x02fced);
    int alpha = 200;
    
    ofColor aqua(0, 252, 255, alpha);
    ofColor purple(198, 0, 205, alpha);
    ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
    ofSetColor(inbetween);
    circle_sin.close(); // to connect first and last point of our shape we need to use ÔcloseÕ function
    circle_sin= circle_sin.getSmoothed(smoothing_amount);
    circle_sin.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    for (int i=0; i < MAX_AGENTS; i++) {
        Agents[i].calcGravityWell(x,y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Agents[curAgent].start(x, y);
    curAgent++;
    if (curAgent >= MAX_AGENTS) {  // make sure it does not go over
        curAgent = 0;
    }
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
