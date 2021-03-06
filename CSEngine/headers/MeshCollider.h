#ifndef GAME_ENGINE_MESHCOLLIDER_H
#define GAME_ENGINE_MESHCOLLIDER_H



namespace CSEngine {

	class Mesh;

	//!UNFINISHED A Collider that uses the mesh for collision detection
	class MeshCollider : public Collider3D {

	private:
		std::weak_ptr<Mesh> mesh;
		void UpdateBounds();

	public:

		void CheckCollision(std::shared_ptr<Collider3D> _col);
		void TestBoxCollider(std::shared_ptr<BoxCollider3D> _col);
		void TestMeshCollider(std::shared_ptr<MeshCollider> _col);
		void TestSphereCollider(std::shared_ptr<SphereCollider> _col);

	};

}//namespace CSEngine

#endif
