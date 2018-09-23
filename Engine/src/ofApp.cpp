#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sys = new SpriteSystem("Player's Spawns");
    player = new Player("Michael", sys);
    background.load("images/Background.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    sys-> update();
    player->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0,0);
    sys-> draw();
    player-> draw();
   
  
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    player-> keypressed_logic(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    player-> keyreleased_logic(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    cout << x << " " <<y << endl;
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
