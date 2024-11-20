#pragma once
#include <cmath>
#include "UC_TEAMS.h"
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

	public ref class MyForm : public Form
	{
	public:
		MyForm(void);
	protected:
		~MyForm();

            virtual property System::Windows::Forms::CreateParams^ CreateParams
            {
                System::Windows::Forms::CreateParams^ get() override
                {
                    System::Windows::Forms::CreateParams^ cp = Form::CreateParams;
                    cp->ExStyle |= 0x02000000; // WS_EX_COMPOSITED
                    return cp;
                }
            }
			Bitmap^ BackGround;
			Bitmap^ BackGroundTemp;
	protected: virtual void OnPaint(PaintEventArgs^ e) override
			{
				Graphics^ dc = e->Graphics;
				dc->DrawImageUnscaled(BackGround, 0, 0);
				__super::OnPaint(e);
			}
            protected:
                !MyForm()
                {
                    if (components != nullptr)
                    {
                        delete components;
                    }
                    if (BackGroundTemp != nullptr)
                    {
                        delete BackGroundTemp;
                    }
                    if (BackGround != nullptr)
                    {
                        delete BackGround;
                    }
                }
	private: void initialize()
	{
		SetStyle(ControlStyles::UserPaint, true);
		SetStyle(ControlStyles::AllPaintingInWmPaint, true);
		SetStyle(ControlStyles::DoubleBuffer, true);
		Assembly^ assembly = Assembly::GetExecutingAssembly();
		ResourceManager^ rm = gcnew ResourceManager("Form2.MyForm", assembly);
		Object^ resource = rm->GetObject(L"$This.BackgroundImage");
		Image^ image;
		if (resource->GetType() == array<Byte>::typeid)
		{
			array<Byte>^ bytes = (array<Byte>^)resource;
			System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(bytes);
			image = Image::FromStream(ms);
		}
		else
		{
			image = (Image^)resource;
		}

		BackGroundTemp = gcnew Bitmap(image);
		BackGround = gcnew Bitmap(BackGroundTemp, BackGroundTemp->Width, BackGroundTemp->Height);
	}
	private:
		System::ComponentModel::Container^ components;
		System::Drawing::Size formSize;
		MenuStrip^ MAINBUTTON;
		ToolStripMenuItem^ HOME;
		ToolStripMenuItem^ TEAMS;
		ToolStripMenuItem^ MATCHES;
		ToolStripMenuItem^ STATS;
		ToolStripMenuItem^ RANKING;
		ToolStripMenuItem^ PLAYERS;
		ToolStripMenuItem^ hoveredItem = nullptr;
		ToolStripMenuItem^ currentMenuItem = nullptr;
	private: Dictionary<ToolStripMenuItem^, Rectangle>^ itemOriginalRectangles;
	private: Rectangle originalFormSize;
		Panel^ ContainerPanel;
		int hoveredIndex = -1;
		bool dragging = false;
		Point offset;
		Tournament* tour;

		   void InitializeComponent(void);
		   void MyForm_Load(Object^ sender, EventArgs^ e);
		   void ConfigureMainMenuStrip();
		   void ConfigureMenuItem(ToolStripMenuItem^ item, String^ text, EventHandler^ click);
		   void ConfigureContainerPanel();
		   void OnResize(Object^ sender, EventArgs^ e);
		   System::Void OnMouseDown(Object^ sender, MouseEventArgs^ e);
		   System::Void OnMouseMove(Object^ sender, MouseEventArgs^ e);
		   System::Void OnMouseUp(Object^ sender, MouseEventArgs^ e);
		   System::Void HOME_Click(Object^ sender, EventArgs^ e);
		   System::Void TEAMS_Click(Object^ sender, EventArgs^ e);
		   System::Void MATCHES_Click(Object^ sender, EventArgs^ e);
		   System::Void STATS_Click(Object^ sender, EventArgs^ e);
		   System::Void RANKING_Click(Object^ sender, EventArgs^ e);
		   System::Void PLAYERS_Click(Object^ sender, EventArgs^ e);
		   void OnMenuItemHover(Object^ sender, EventArgs^ e);
		   void OnMenuItemLeave(Object^ sender, EventArgs^ e);
		   void OnMenuStripPaint(Object^ sender, PaintEventArgs^ e);
		   void ResetButtonColors();
		   System::Void addUserControl(UserControl^ userControl);
	};
}
