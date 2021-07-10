#pragma once

#include "Coffee/Layer.h"

#include "Coffee/Events/ApplicationEvent.h"
#include "Coffee/Events/MouseEvent.h"
#include "Coffee/Events/KeyEvent.h"

namespace Coffee {

	class COFFEE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.f;
	};
}