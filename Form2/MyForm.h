#pragma once
#include <cmath>
#include "UC_TEAMS.h"

namespace Form2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);
	protected:
		~MyForm();
		virtual void WndProc(System::Windows::Forms::Message% m) override;
	private:
		System::ComponentModel::Container^ components;
		System::Drawing::Size formSize;
		System::Windows::Forms::MenuStrip^ MAINBUTTON;
		System::Windows::Forms::ToolStripMenuItem^ TEAMS;
		System::Windows::Forms::ToolStripMenuItem^ MATCHES;
		System::Windows::Forms::ToolStripMenuItem^ STATS;
		System::Windows::Forms::ToolStripMenuItem^ RANKING;
		System::Windows::Forms::ToolStripMenuItem^ PLAYERS;
		System::Windows::Forms::ToolStripMenuItem^ hoveredItem = nullptr;
		System::Windows::Forms::ToolStripMenuItem^ currentMenuItem = nullptr;
		int hoveredIndex = -1;
		bool dragging = false;
	private: System::Windows::Forms::Panel^ ContainerPanel;
	private: System::Windows::Forms::ToolStripMenuItem^ HOME;

		   Point offset;

		void InitializeComponent(void);
		void OnResize(Object^ sender, EventArgs^ e);
		System::Void OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void TEAMS_Click(System::Object^ sender, System::EventArgs^ e);
		void OnMenuItemHover(Object^ sender, EventArgs^ e);
		void OnMenuItemLeave(Object^ sender, EventArgs^ e);
		void OnMenuStripPaint(Object^ sender, PaintEventArgs^ e);
		void ResetButtonColors();
		System::Void addUserControl(UserControl^ userControl);
	private: System::Void HOME_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
