#ifndef GAME_ENGINE_BOUNDBOX_H
#define GAME_ENGINE_BOUNDBOX_H

#include <vector>
#include <glm\glm.hpp>

namespace GameEngine {

	//! A simple bounding box
	class BoundBox {

	private:
		glm::vec3 min;
		glm::vec3 max;
		//!The distance between the minimum and maximum points of the bounding box
		glm::vec3 size;
		//!The position exactly halfway between the minimum and maximum
		glm::vec3 centre;
		//!The vector distance between the centre and the minimum or maximum (half of the size)
		glm::vec3 extents;

	public:
		//!Generate a BoundBox with size (0,0,0)
		BoundBox();
		//!Generate a BoundBox using preset size and centre point
		BoundBox(glm::vec3 _centre, glm::vec3 _size);

		void SetMinMax(glm::vec3 _min, glm::vec3 _max);
		glm::vec3 GetMin() { return min; }
		glm::vec3 GetMax() { return max; }
		glm::vec3 GetSize() { return size; }
		glm::vec3 GetCentre() { return centre; }
		glm::vec3 GetExtents() { return extents; }

	};

}//namespace GameEngine

#endif
