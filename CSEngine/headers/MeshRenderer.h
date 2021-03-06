#ifndef GAME_ENGINE_MESHRENDERER_H
#define GAME_ENGINE_MESHRENDERER_H

namespace CSEngine {

	class BoundBox3D;

	class Mesh;

	//!Component class. Handles rendering an attached Mesh
	class MeshRenderer : public Component {

	private:
		//!The mesh attached to this renderer. Defaults to "cube.obj"
		std::shared_ptr<Mesh> mesh;

		GLuint vaoId;
		GLuint positionVboId;
		GLuint normalVboId;
		GLuint textureVboId;

		GLuint modelLoc;

		void Draw();
		void OnAwake();

		//!Creates the GL Vertex Array Buffer for the attached mesh.
		void CreateVao();

		//!Select whether to scale mesh 
		bool autoScale;

	public:
		void SetAutoScale(bool _autoScale);
		//!Returns the mesh attached to this MeshRenderer.
		std::shared_ptr<Mesh> GetMesh() { return mesh; }
		//!Changes the mesh attached to this MeshRenderer. This will also regenerate the GL information.
		void SetMesh(std::string _meshName);
		BoundBox3D GetMeshBounds() const;
		float GetMeshRadius() const;
	};
}//namespace CSEngine

#endif
