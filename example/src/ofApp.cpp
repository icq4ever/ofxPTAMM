#include "ofApp.h"

void ofApp::setup(){
	ofEnableAlphaBlending();
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	
	camWidth 		= 640;
	camHeight 		= 480;
	
	ptamm.init(camWidth,camHeight);
	
	grabber.initGrabber(camWidth,camHeight);
    video.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
#ifdef CAMARACALIBRATION
    ccam.init(camWidth, camHeight);
#endif
    // ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();
	
	// loads the OF logo from disk
    logo.loadImage("of.png");
}

void ofApp::update(){
    grabber.update();
    
    if (grabber.isFrameNew()){
        video.setFromPixels(grabber.getPixels(),camWidth,camHeight,OF_IMAGE_COLOR);
        video.mirror(false, true);
        video.update();
        ptamm.update( video.getPixels() );
#ifdef CAMARACALIBRATION
        ccam.update( video.getPixels() );
#endif
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

void ofApp::draw(){
    ofSetColor(255, 255);
    video.draw(0,0);
    
    ofSetColor(255, 255);
	ptamm.draw();
    
#ifdef CAMARACALIBRATION
    ofSetColor(255, 255);
    ccam.draw();
#endif
    
    if ( ptamm.isMapBuild() ){
        cam.begin();
        ofPushMatrix();
		
        ptamm.moveCamera();
    
        ofTranslate(0, 0, -50);
        
        logo.bind();
        ofFill();
        ofSetColor(255);
        ofBox(100);
        logo.unbind();
		
        ofPopMatrix();
        cam.end();
    }
    
}


void ofApp::keyPressed(int key){
	switch (key){
		case ' ':
			ptamm.buildMap();
			break;
		case 'r':
			ptamm.resetAll();
			break;
        case 'n':
            ptamm.newMap();
			break;
        case 'd':
            ptamm.newMap();
            ptamm.switchMap((ptamm.getActualMap()-1)%ptamm.getTotalMaps());
            ptamm.deleteMap(ptamm.getActualMap());
			break;
        case OF_KEY_LEFT:
            ptamm.switchMap((ptamm.getActualMap()-1)%ptamm.getTotalMaps());
            break;
        case OF_KEY_RIGHT:
            ptamm.switchMap((ptamm.getActualMap()+1)%ptamm.getTotalMaps());
            break;
        case 's':
            ptamm.saveMap();
			break;
        case 'l':
            ptamm.loadMap();
			break;
        case 'p':
            ptamm.bDebug = !ptamm.bDebug;
			break;
#ifdef CAMARACALIBRATION
        case OF_KEY_RETURN:
            ccam.grabPicture();
            break;
        case 'o':
            ccam.bOptimizing = !ccam.bOptimizing;
            break;
        case OF_KEY_UP:
            ccam.viewImage( (ccam.getActualImage()-1)%ccam.getTotalImages());
            break;
        case OF_KEY_DOWN:
            ccam.viewImage( (ccam.getActualImage()+1)%ccam.getTotalImages());
            break;
#endif
	}
}

void ofApp::keyReleased(int key){ 

}

void ofApp::mouseMoved(int x, int y ){ 

}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button) {
	
}

void ofApp::mouseReleased(){

}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::windowResized(int w, int h){
    
}

