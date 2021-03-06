#include "CSEngine_Common.h"

#include "Collision3D.h"


namespace CSEngine
{
	//==============================================================================
	Component::Component()
	{

	}//Component::Component
	//==============================================================================
	void Component::Start()
	{
		OnStart();
	}//Component::Start
	//==============================================================================
	void Component::Draw()
	{
		OnDraw();
	}//Component::OnDraw
	//==============================================================================
	void Component::Awake()
	{
		OnAwake();
	}//Component::Awake
	//==============================================================================
	void Component::Destroy()
	{
		OnDestroy();
	}//Component::Destroy
	//==============================================================================
	void Component::Update()
	{
		OnUpdate();
	}//Component::Update
	//==============================================================================
	void Component::OnDestroy()
	{
	}//Component::OnDestroy
	//==============================================================================
	void Component::OnAwake()
	{

	}//Component::OnAwake
	//==============================================================================
	void Component::OnUpdate()
	{

	}//Component::OnUpdate
	//==============================================================================
	void Component::OnStart()
	{

	}//Component::OnStart
	//==============================================================================
	void Component::OnDraw()
	{

	}//Component::OnDraw
	//==============================================================================
	std::weak_ptr<Transform> Component::GetTransform() const
	{
		return gameObject.lock()->GetTransform();
	}//Component::GetTransform
	 //==============================================================================
	void Component::OnCollision3D(Collision3D _col)
	{

	}//Component::OnCollision3D

}
