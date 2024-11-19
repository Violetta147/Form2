#pragma once
#include <cmath>
#include "UC_HOME.h"
#include "UC_TEAMS.h"
#include "UC_PLAYERS.h"
#include "UC_MATCHES.h"
#include "UC_STATS.h"
#include "UC_RANKING.h"
#include "TransparentRenderer.h"
#include "include/Event.h"
#include "include/Team.h"
#include "include/Player.h"
#include "include/Match.h"
#include "include/Tournament.h"
#include "include/file_handler.h"
#include "include/nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

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
		System::Windows::Forms::ToolStripMenuItem^ HOME;
		System::Windows::Forms::ToolStripMenuItem^ TEAMS;
		System::Windows::Forms::ToolStripMenuItem^ MATCHES;
		System::Windows::Forms::ToolStripMenuItem^ STATS;
		System::Windows::Forms::ToolStripMenuItem^ RANKING;
		System::Windows::Forms::ToolStripMenuItem^ PLAYERS;
		System::Windows::Forms::ToolStripMenuItem^ hoveredItem = nullptr;
		System::Windows::Forms::ToolStripMenuItem^ currentMenuItem = nullptr;
		System::Windows::Forms::Panel^ ContainerPanel;
		int hoveredIndex = -1;
		bool dragging = false;
		Point offset;
		Tournament* tour;

		void InitializeComponent(void);
		void OnResize(Object^ sender, EventArgs^ e);
		System::Void OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

		System::Void HOME_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TEAMS_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void PLAYERS_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MATCHES_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void STATS_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void RANKING_Click(System::Object^ sender, System::EventArgs^ e);

		void OnMenuItemHover(Object^ sender, EventArgs^ e);
		void OnMenuItemLeave(Object^ sender, EventArgs^ e);
		void OnMenuStripPaint(Object^ sender, PaintEventArgs^ e);
		void ResetButtonColors();
		System::Void addUserControl(UserControl^ userControl);
	};
}
