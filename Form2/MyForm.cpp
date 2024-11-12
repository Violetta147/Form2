#include "MyForm.h"

Form2::MyForm::MyForm(void)
{
	InitializeComponent();
	formSize = this->ClientSize;
}

Form2::MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}

void Form2::MyForm::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	this->MAINBUTTON = (gcnew System::Windows::Forms::MenuStrip());
	this->TEAMS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->MATCHES = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->STATS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->RANKING = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->MAINBUTTON->SuspendLayout();
	this->SuspendLayout();

	// MAINBUTTON
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
	this->MAINBUTTON->Size = System::Drawing::Size(1200, 64);
	this->MAINBUTTON->TabIndex = 0;
	this->MAINBUTTON->Text = L"menuStrip1";
	// TEAMS
	this->TEAMS->AutoSize = false;
	this->TEAMS->ForeColor = System::Drawing::Color::White;
	this->TEAMS->Name = L"TEAMS";
	this->TEAMS->Size = System::Drawing::Size(200, 24);
	this->TEAMS->Text = L"TEAMS";
	// MATCHES
	this->MATCHES->AutoSize = false;
	this->MATCHES->ForeColor = System::Drawing::Color::White;
	this->MATCHES->Name = L"MATCHES";
	this->MATCHES->Size = System::Drawing::Size(200, 24);
	this->MATCHES->Text = L"MATCHES";
	// STATS
	this->STATS->AutoSize = false;
	this->STATS->ForeColor = System::Drawing::Color::White;
	this->STATS->Name = L"STATS";
	this->STATS->Size = System::Drawing::Size(200, 24);
	this->STATS->Text = L"STATS";
	// RANKING
	this->RANKING->AutoSize = false;
	this->RANKING->ForeColor = System::Drawing::Color::White;
	this->RANKING->Name = L"RANKING";
	this->RANKING->Size = System::Drawing::Size(200, 24);
	this->RANKING->Text = L"RANKING";
	// MyForm
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

void Form2::MyForm::OnResize(Object^ sender, EventArgs^ e)
{
	// Container width (MenuStrip)
	int containerWidth = this->ClientSize.Width;
	int numButtons = 4;
	int padding = 10; // Padding between buttons (space between buttons)

	// Subtract left and right margins for centering the buttons
	int marginSpace = 40;  // Total margin space to be distributed on both sides of the buttons (can be adjusted)
	int availableWidth = containerWidth - marginSpace;
	int buttonWidth = (availableWidth - (numButtons - 1) * padding) / numButtons;

	// Optionally, ensure the buttons are not too wide (set a max width if necessary)
	buttonWidth = std::fmin(buttonWidth, 200); 
	int totalButtonWidth = (buttonWidth * numButtons) + (padding * (numButtons - 1));
	int remainingWidth = containerWidth - totalButtonWidth;
	// Distribute the remaining width as margins on both sides (left and right)
	int leftMargin = remainingWidth / 2;
	int rightMargin = remainingWidth / 2;

	this->MAINBUTTON->Padding = System::Windows::Forms::Padding(leftMargin, 0, rightMargin, 0);
	for each (ToolStripMenuItem ^ item in this->MAINBUTTON->Items)
	{
		item->AutoSize = false;  
		item->Width = buttonWidth; 
		item->TextAlign = ContentAlignment::MiddleCenter; 
	}
}

void Form2::MyForm::OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		dragging = true;
		offset = Point(e->X, e->Y);
	}
}

void Form2::MyForm::OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (dragging)
	{
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);
	}
}

void Form2::MyForm::OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		dragging = false;
	}
}

void Form2::MyForm::WndProc(System::Windows::Forms::Message% m) 
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