#pragma once

#include "Actor.h"

#include "Renderer/Model.h"

namespace Engine {

	struct DrawProps
	{
		glm::vec3 PositionVector;
		glm::vec3 AnimationVector;

		DrawProps(glm::vec3 position = glm::vec3(0.0f), glm::vec3 anim = glm::vec3(1.0f))
			: PositionVector(position), AnimationVector(anim) {}
	};

	class Pastry : public Actor
	{
	public:
		Pastry(Model* model, const DrawProps& props = DrawProps(), const std::string& name = "")
			: m_Model(model), m_Velocity(glm::vec3(0.0f)), m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
			m_Up(glm::vec3(0.0f, 1.0f, 0.0f)), m_Right(glm::vec3(1.0f, 0.0f, 0.0f)) ,
			m_Position(glm::vec3(props.PositionVector)), m_AnimationVector(props.AnimationVector),
			m_Name(name), m_ModelMatrix(glm::mat4(1.0f)) 
		{
			m_StartPosition = m_Position;
			m_ModelMatrix = glm::mat4(1.0f);
			ApplyForce();
		}

		~Pastry();
		
		virtual void OnUpdate(float dt) override;
		virtual void OnEvent(Event& event) override;
		virtual void Draw(Shader* shader) override;

		virtual void ApplyForce(glm::vec3 force = glm::vec3(0.0f, 18.0f, 0.0f)) override;

		glm::vec2 GetScreenCoordinates() const;

		std::string m_Name;
	private:
		Model* m_Model;
		
		/// Object Properties
		glm::mat4 m_ModelMatrix;
		glm::vec3 m_Position, m_StartPosition, m_Velocity, m_AnimationVector, m_Up, m_Front, m_Right;
		
		/// Gravity Vector
		const glm::vec3 m_GravityVector = glm::vec3(0.0f, -9.8f, 0.f);
	};

}

