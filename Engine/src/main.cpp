#include "ofMain.h"
#include "ofApp.h"


/* Credit
    Laser-Beam : http://pixelartmaker.com/art/8c8b1d81151796e
    Background : https://stmed.net/wallpaper-129483
    Spaceship  : https://www.deviantart.com/albertov/art/SpaceShip-286028639
    Bullet Sound : generated on https://www.bfxr.net/
*/
//========================================================================
int main( ){
	ofSetupOpenGL(1080, 1920, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
