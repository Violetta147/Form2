#pragma once
#include <cmath>

namespace Form2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			formSize = this->ClientSize;
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool dragging = false;
		System::Drawing::Size formSize;
	private: System::Windows::Forms::MenuStrip^ MAINBUTTON;
	private: System::Windows::Forms::ToolStripMenuItem^ TEAMS;
	private: System::Windows::Forms::ToolStripMenuItem^ MATCHES;
	private: System::Windows::Forms::ToolStripMenuItem^ STATS;
	private: System::Windows::Forms::ToolStripMenuItem^ RANKING;

		   Point offset;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->MAINBUTTON = (gcnew System::Windows::Forms::MenuStrip());
			this->TEAMS = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MATCHES = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->STATS = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RANKING = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MAINBUTTON->SuspendLayout();
			this->SuspendLayout();
			// 
			// MAINBUTTON
			// 
			this->MAINBUTTON->AutoSize = false;
			this->MAINBUTTON->BackColor = System::Drawing::Color::Transparent;
			this->MAINBUTTON->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MAINBUTTON->ImageScalingSize = System::Drawing::Size(20, 20);
			this->MAINBUTTON->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->TEAMS, this->MATCHES,
					this->STATS, this->RANKING
			});
			this->MAINBUTTON->Location = System::Drawing::Point(0, 0);
			this->MAINBUTTON->Name = L"MAINBUTTON";
			this->MAINBUTTON->Padding = System::Windows::Forms::Padding(185, 2, 185, 2);
			this->MAINBUTTON->Size = System::Drawing::Size(1200, 28);
			this->MAINBUTTON->TabIndex = 0;
			this->MAINBUTTON->Text = L"menuStrip1";
			// 
			// TEAMS
			// 
			this->TEAMS->AutoSize = false;
			this->TEAMS->Name = L"TEAMS";
			this->TEAMS->Size = System::Drawing::Size(200, 24);
			this->TEAMS->Text = L"TEAMS";
			// 
			// MATCHES
			// 
			this->MATCHES->AutoSize = false;
			this->MATCHES->Name = L"MATCHES";
			this->MATCHES->Size = System::Drawing::Size(200, 24);
			this->MATCHES->Text = L"MATCHES";
			// 
			// STATS
			// 
			this->STATS->AutoSize = false;
			this->STATS->Name = L"STATS";
			this->STATS->Size = System::Drawing::Size(200, 24);
			this->STATS->Text = L"STATS";
			// 
			// RANKING
			// 
			this->RANKING->AutoSize = false;
			this->RANKING->Name = L"RANKING";
			this->RANKING->Size = System::Drawing::Size(200, 24);
			this->RANKING->Text = L"RANKING";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->MAINBUTTON);
			this->MainMenuStrip = this->MAINBUTTON;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"MyForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseUp);
			this->Resize += gcnew System::EventHandler(this, &MyForm::OnResize);
			this->MAINBUTTON->ResumeLayout(false);
			this->MAINBUTTON->PerformLayout();
			this->ResumeLayout(false);

		}
		// OnResize method to dynamically adjust button sizes and margins
		void MyForm::OnResize(Object^ sender, EventArgs^ e)
		{
			// Container width (MenuStrip)
			int containerWidth = this->ClientSize.Width;

			// Number of buttons
			int numButtons = 4;

			// Padding between buttons (space between buttons)
			int padding = 10;  // Space between buttons (can be adjusted)

			// Subtract left and right margins for centering the buttons
			int marginSpace = 40;  // Total margin space to be distributed on both sides of the buttons (can be adjusted)

			// Calculate the total available width for buttons
			int availableWidth = containerWidth - marginSpace;

			// Calculate the width of each button (excluding the padding between them)
			int buttonWidth = (availableWidth - (numButtons - 1) * padding) / numButtons;

			// Optionally, ensure the buttons are not too wide (set a max width if necessary)
			buttonWidth = std::fmin(buttonWidth, 200);  // Maximum width of the buttons (can be adjusted)

			// Now, calculate the total width used by the buttons and padding
			int totalButtonWidth = (buttonWidth * numButtons) + (padding * (numButtons - 1));

			// Calculate the remaining space (this will be distributed as margins)
			int remainingWidth = containerWidth - totalButtonWidth;

			// Distribute the remaining width as margins on both sides (left and right)
			int leftMargin = remainingWidth / 2;
			int rightMargin = remainingWidth / 2;

			// Set the calculated margins for the MenuStrip
			this->MAINBUTTON->Padding = System::Windows::Forms::Padding(leftMargin, 0, rightMargin, 0);

			// Adjust the width of each button
			for each (ToolStripMenuItem ^ item in this->MAINBUTTON->Items)
			{
				item->AutoSize = false;  // Disable auto-sizing
				item->Width = buttonWidth;  // Set the width based on the calculation
				item->TextAlign = ContentAlignment::MiddleCenter;  // Align the text in the center of each button
			}
		}
#pragma endregion
	private:
		System::Void OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				dragging = true;
				offset = Point(e->X, e->Y);
			}
		}
		System::Void OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if (dragging)
			{
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);
			}
		}
		System::Void OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				dragging = false;
			}
		}
	protected:
		virtual void WndProc(System::Windows::Forms::Message% m) override
		{
			const int WM_NCCALCSIZE = 0x0083;
			const int WM_SYSCOMMAND = 0x0112;
			const int SC_MINIMIZE = 0xF020;
			const int SC_RESTORE = 0xF120;
			const int WM_NCHITTEST = 0x0084;
			const int resizeAreaSize = 10;

			// Resize/WM_NCHITTEST values
			const int HTCLIENT = 1;
			const int HTLEFT = 10;
			const int HTRIGHT = 11;
			const int HTTOP = 12;
			const int HTTOPLEFT = 13;
			const int HTTOPRIGHT = 14;
			const int HTBOTTOM = 15;
			const int HTBOTTOMLEFT = 16;
			const int HTBOTTOMRIGHT = 17;

			if (m.Msg == WM_NCHITTEST)
			{
				System::Windows::Forms::Form::WndProc(m);
				if (this->WindowState == System::Windows::Forms::FormWindowState::Normal)
				{
					if ((int)m.Result == HTCLIENT)
					{
						System::Drawing::Point screenPoint = System::Drawing::Point(m.LParam.ToInt32());
						System::Drawing::Point clientPoint = this->PointToClient(screenPoint);

						if (clientPoint.Y <= resizeAreaSize)
						{
							if (clientPoint.X <= resizeAreaSize)
								m.Result = (System::IntPtr)HTTOPLEFT;
							else if (clientPoint.X < (this->Size.Width - resizeAreaSize))
								m.Result = (System::IntPtr)HTTOP;
							else
								m.Result = (System::IntPtr)HTTOPRIGHT;
						}
						else if (clientPoint.Y <= (this->Size.Height - resizeAreaSize))
						{
							if (clientPoint.X <= resizeAreaSize)
								m.Result = (System::IntPtr)HTLEFT;
							else if (clientPoint.X > (this->Width - resizeAreaSize))
								m.Result = (System::IntPtr)HTRIGHT;
						}
						else
						{
							if (clientPoint.X <= resizeAreaSize)
								m.Result = (System::IntPtr)HTBOTTOMLEFT;
							else if (clientPoint.X < (this->Size.Width - resizeAreaSize))
								m.Result = (System::IntPtr)HTBOTTOM;
							else
								m.Result = (System::IntPtr)HTBOTTOMRIGHT;
						}
					}
				}
				return;
			}

			// Remove border and keep snap window
			if (m.Msg == WM_NCCALCSIZE && m.WParam.ToInt32() == 1)
			{	
				System::Windows::Forms::Form::WndProc(m);
				return;
			}

			// Handle minimize and restore to keep form size
			if (m.Msg == WM_SYSCOMMAND)
			{
				int wParam = (m.WParam.ToInt32() & 0xFFF0);
				if (wParam == SC_MINIMIZE)
					formSize = this->ClientSize;
				if (wParam == SC_RESTORE)
					this->Size = formSize;
			}
			System::Windows::Forms::Form::WndProc(m);
		}
};
}
