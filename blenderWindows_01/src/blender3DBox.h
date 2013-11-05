/*
 * blender3DBox.h
 *
 *  Created on: Nov 5, 2013
 *      Author: arnaud
 */

#ifndef BLENDER3DBOX_H_
#define BLENDER3DBOX_H_

#include "ofMain.h"

class blender3DBox: public ofNode
{
public:
	virtual ~blender3DBox();
	blender3DBox();

	void customDraw();

	ofMesh boxMesh;
};

#endif /* BLENDER3DBOX_H_ */
