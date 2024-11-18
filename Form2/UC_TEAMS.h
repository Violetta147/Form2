#pragma once
#include "resource.h"
#include "include/Tournament.h"
#include <Windows.h>
#pragma comment(lib, "User32.lib")
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Resources;
using namespace System::Reflection;
//using namespace System::Runtime::InteropServices;
//using namespace System::IO;


namespace Form2 {

	public ref class UC_TEAMS : public System::Windows::Forms::UserControl
	{
	public:
		UC_TEAMS(Tournament* tour)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &Form2::UC_TEAMS::UC_TEAMS_Load);
			this->Resize += gcnew EventHandler(this, &UC_TEAMS::UC_TEAMS_Resize);
			this->Controls->Add(tableLayoutPanel);
			tableLayoutPanel->Dock = DockStyle::Fill;
			this->tour = tour;
		}

	protected:
		~UC_TEAMS()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::Container ^components;
		TableLayoutPanel^ tableLayoutPanel = gcnew TableLayoutPanel();
		int minButtonsPerRow = 2;
		int maxButtonsPerRow = 5;
		const int buttonWidth = 150;
		Tournament* tour;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Name = L"UC_TEAMS";
			this->Size = System::Drawing::Size(992, 661);
			this->ResumeLayout(false);
		}

		void UC_TEAMS_Load(Object^ sender, EventArgs^ e)
		{
			int teamCount = tour->get_team_count();
			GenerateTeamButtons(teamCount);
		}
		void UC_TEAMS_Resize(Object^ sender, EventArgs^ e)
		{
			int teamCount = tour->get_team_count();
			GenerateTeamButtons(teamCount);
		}
		void GenerateTeamButtons(int teamCount)
		{
			int buttonsPerRow = std::fmax(minButtonsPerRow, std::fmin(maxButtonsPerRow, this->tableLayoutPanel->Width / buttonWidth));
			int rows = (int)ceil((double)teamCount / buttonsPerRow);

			this->tableLayoutPanel->Controls->Clear();
			this->tableLayoutPanel->ColumnCount = buttonsPerRow;
			this->tableLayoutPanel->RowCount = rows;

			this->tableLayoutPanel->ColumnStyles->Clear();
			for (int i = 0; i < buttonsPerRow; i++)
			{
				this->tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100 / buttonsPerRow));
			}
			this->tableLayoutPanel->RowStyles->Clear();
			for (int i = 0; i < rows; i++)
			{
				this->tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100 / rows));
			}
			for (int i = 0; i < teamCount; i++)
			{
				Button^ button = gcnew Button();
				button->Name = "button" + (i + 1).ToString();
				button->BackgroundImage = GetImageResource(button->Name + "_Default");
				button->BackgroundImageLayout = ImageLayout::Zoom;
				button->Dock = DockStyle::Fill;

				button->MouseEnter += gcnew EventHandler(this, &UC_TEAMS::Button_MouseEnter);
				button->MouseLeave += gcnew EventHandler(this, &UC_TEAMS::Button_MouseLeave);

				this->tableLayoutPanel->Controls->Add(button, i % buttonsPerRow, i / buttonsPerRow);
			}
		}
		int GetResourceId(String^ resourceName)
		{
			if (resourceName == "button1_Default") return IDB_PNG1;
			if (resourceName == "button1_Hover") return IDB_PNG2;

			return -1;
		}
		Image^ GetImageResource (String^ resourceName)
		{
			int resourceId = GetResourceId(resourceName);
			if (resourceId == -1)
			{
				return nullptr;
			}
			return GetImageResource(resourceId);
		}

		Image^ GetImageResource(int resourceId)
		{
            HINSTANCE hInstance = (HINSTANCE)System::Runtime::InteropServices::Marshal::GetHINSTANCE(this->GetType()->Module).ToPointer();
			HBITMAP hBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(resourceId), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);

			if (hBitmap == nullptr)
			{
				return nullptr; // Failed to load
			}

			return Image::FromHbitmap(IntPtr(hBitmap)); // Convert HBITMAP to managed Image^
		}
		void Button_MouseEnter(Object^ sender, EventArgs^ e)
		{
			Button^ button = (Button^)sender;
			button->BackgroundImage = GetImageResource(button->Name + "_Hover");
		}
		void Button_MouseLeave(Object^ sender, EventArgs^ e)
		{
			Button^ button = (Button^)sender;
			button->BackgroundImage = GetImageResource(button->Name + "_Default");
		}
#pragma endregion

};
}
