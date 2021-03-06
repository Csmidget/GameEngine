#ifndef GAME_ENGINE_MESH_H
#define GAME_ENGINE_MESH_H

namespace CSEngine {

	//!Stores triangle specific information. Indices for position, normal and texture co-ordinates.
	struct Triangle
	{
		glm::ivec3 posIndices;
		glm::ivec3 texIndices;
		glm::ivec3 normalIndices;
	};

	//!Stores all vertex,material and texture information of a mesh.
	class Mesh {

		friend class MeshLoader;
		friend class MeshRenderer;

	private:

		//!List of all triangles in the mesh
		std::vector<Triangle> triangles;

		//!Raw dump of position vertex values.
		std::vector<glm::vec4> rawVertices;
		//!Raw dump of normal vertex values.
		std::vector<glm::vec3> rawNormals;
		//!Raw dump of texture coordinate vertex values.
		std::vector<glm::vec2> rawTexCoords;

		//!Sorted list of position vertices, 3 per triangle.
		std::vector<glm::vec4> posVertices;
		//!Sorted list of normal vertices, 3 per triangle.
		std::vector<glm::vec3> normalVertices;
		//!Sorted list of texture coordinate vertices, 3 per triangle.
		std::vector<glm::vec2> texVertices;

		//!Sorted list of scaled position vertices, 3 per triangle.
		std::vector<glm::vec4> scaledPosVertices;

		//!List of materials attached to this mesh. Currently only the first material is used.
		std::vector<tinyobj::material_t> materials;
		//!Static list of all loaded meshes. Each mesh can be used by multiple objects.
		static std::map<std::string, std::weak_ptr<Mesh>> loadedMeshes;
		//!Static list of all loaded textures. Each texture can be used by multiple objects.
		static std::map<std::string, GLuint> textures;

		//!Radius of mesh. Length of vector for longest vertex on each axis.
		float radius;

		float scaledRadius;

		//!Recalculates the bounding box of this mesh
		void RecalcBounds();

		//!Bounding box encompassing all vertices of the mesh
		BoundBox3D bounds;
		BoundBox3D scaledBounds;
	public:

		Mesh();
		//!Returns the list of raw position vertices
		std::vector<glm::vec4> GetVertices() const { return rawVertices; }
		//!Returns the list of raw texture coordinate vertices
		std::vector<glm::vec2> GetTexCoords() const { return rawTexCoords; }
		//!Returns the list of materials for this mesh
		std::vector<tinyobj::material_t> GetMaterials() const { return materials; }
		//!Returns the list of this meshes triangles
		std::vector<Triangle> GetTriangles() const { return triangles; }
		//!Returns the GLuint for a texture with name _texName
		static GLuint GetTexture(std::string _texName) { return textures.at(_texName); }

		//!Returns the bounding box of this mesh
		BoundBox3D GetBounds() const { return bounds; }
		BoundBox3D GetScaledBounds() const { return scaledBounds; }
		//!Returns this meshes radius
		float GetRadius() const { return radius; }
		float GetScaledRadius() const { return scaledRadius; }
	};
}//namespace CSEngine

#endif
