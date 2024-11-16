#include "MyForm.h"
//#include "Neon.h"
#include "TransparentRenderer.h"

Form2::MyForm::MyForm(void)
{
	InitializeComponent();
	formSize = this->ClientSize;
	this->MAINBUTTON->Renderer = gcnew TransparentRenderer();
	//this->MAINBUTTON->Renderer = gcnew NeonMenuRenderer(); // this can be gone if i modify the designer file if it lies in the InitializeCOmponent function
	// Attach MouseEnter and MouseLeave events to all ToolStripMenuItems
	for each (ToolStripMenuItem ^ item in MAINBUTTON->Items)
	{
		item->MouseEnter += gcnew System::EventHandler(this, &Form2::MyForm::OnMenuItemHover);
		item->MouseLeave += gcnew System::EventHandler(this, &Form2::MyForm::OnMenuItemLeave);
	}
	this->MAINBUTTON->Paint += gcnew PaintEventHandler(this, &Form2::MyForm::OnMenuStripPaint); //draw whiteline
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
	this->HOME = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->TEAMS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->PLAYERS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->MATCHES = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->STATS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->RANKING = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->ContainerPanel = (gcnew System::Windows::Forms::Panel());
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
	this->MAINBUTTON->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
		this->HOME, this->TEAMS,
			this->PLAYERS, this->MATCHES, this->STATS, this->RANKING
	});
	this->MAINBUTTON->Location = System::Drawing::Point(0, 0);
	this->MAINBUTTON->Name = L"MAINBUTTON";
	this->MAINBUTTON->Padding = System::Windows::Forms::Padding(240, 2, 240, 2);
	this->MAINBUTTON->Size = System::Drawing::Size(1200, 65);
	this->MAINBUTTON->TabIndex = 0;
	this->MAINBUTTON->Text = L"menuStrip1";
	// 
	// HOME
	// 
	this->HOME->AutoSize = false;
	this->HOME->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->HOME->ForeColor = System::Drawing::Color::White;
	this->HOME->Name = L"HOME";
	this->HOME->Size = System::Drawing::Size(120, 24);
	this->HOME->Text = L"HOME";
	// 
	// TEAMS
	// 
	this->TEAMS->AutoSize = false;
	this->TEAMS->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->TEAMS->ForeColor = System::Drawing::Color::White;
	this->TEAMS->Name = L"TEAMS";
	this->TEAMS->Size = System::Drawing::Size(120, 24);
	this->TEAMS->Text = L"TEAMS";
	this->TEAMS->Click += gcnew System::EventHandler(this, &MyForm::TEAMS_Click);
	// 
	// PLAYERS
	// 
	this->PLAYERS->AutoSize = false;
	this->PLAYERS->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PLAYERS->ForeColor = System::Drawing::Color::White;
	this->PLAYERS->Name = L"PLAYERS";
	this->PLAYERS->Size = System::Drawing::Size(120, 24);
	this->PLAYERS->Text = L"PLAYERS";
	// 
	// MATCHES
	// 
	this->MATCHES->AutoSize = false;
	this->MATCHES->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->MATCHES->ForeColor = System::Drawing::Color::White;
	this->MATCHES->Name = L"MATCHES";
	this->MATCHES->Size = System::Drawing::Size(120, 24);
	this->MATCHES->Text = L"MATCHES";
	// 
	// STATS
	// 
	this->STATS->AutoSize = false;
	this->STATS->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->STATS->ForeColor = System::Drawing::Color::White;
	this->STATS->Name = L"STATS";
	this->STATS->Size = System::Drawing::Size(120, 24);
	this->STATS->Text = L"STATS";
	// 
	// RANKING
	// 
	this->RANKING->AutoSize = false;
	this->RANKING->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->RANKING->ForeColor = System::Drawing::Color::White;
	this->RANKING->Name = L"RANKING";
	this->RANKING->Size = System::Drawing::Size(120, 24);
	this->RANKING->Text = L"RANKING";
	// 
	// ContainerPanel
	// 
	this->ContainerPanel->BackColor = System::Drawing::Color::Transparent;
	this->ContainerPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->ContainerPanel->Location = System::Drawing::Point(0, 65);
	this->ContainerPanel->Name = L"ContainerPanel";
	this->ContainerPanel->Size = System::Drawing::Size(1200, 635);
	this->ContainerPanel->TabIndex = 1;
	// 
	// MyForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
	this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	this->ClientSize = System::Drawing::Size(1200, 700);
	this->Controls->Add(this->ContainerPanel);
	this->Controls->Add(this->MAINBUTTON);
	this->DoubleBuffered = true;
	this->ForeColor = System::Drawing::SystemColors::ControlText;
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
	int numButtons = 6;
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

void Form2::MyForm::OnMenuItemHover(Object^ sender, EventArgs^ e)
{	
	hoveredItem = dynamic_cast<ToolStripMenuItem^>(sender);
	hoveredIndex = this->MAINBUTTON->Items->IndexOf(hoveredItem);
	//currentMenuItem only changes state when there is event of click a button and if 
	//next button click is not the same as the previous one
	if (hoveredItem != nullptr && hoveredItem != currentMenuItem) {
		hoveredItem->ForeColor = Color::LimeGreen;
	}
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
}

void Form2::MyForm::OnMenuItemLeave(Object^ sender, EventArgs^ e)
{
	if (hoveredItem != nullptr && hoveredItem != currentMenuItem) {
		// Revert the text color back to the default 
		hoveredItem->ForeColor = Color::FromArgb(120, Color::White);
	}
	hoveredItem = nullptr;
	hoveredIndex = -1;
	this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
}

void Form2::MyForm::OnMenuStripPaint(Object^ sender, PaintEventArgs^ e)
{
	Graphics^ g = e->Graphics;
	Pen^ pen = gcnew Pen(Color::FromArgb(120, Color::White));

	int startX = this->HOME->Bounds.Left + 10;
	int endX = this->RANKING->Bounds.Right - 10;

	int lineY = this->MAINBUTTON->Height - 15;

	g->DrawLine(pen, startX, lineY, endX, lineY);	
	
	if (hoveredItem != nullptr && hoveredIndex != -1 )
	{
		Pen^ hoverPen = gcnew Pen(Color::LimeGreen, 2.0f);
		Rectangle itemBounds = hoveredItem->Bounds;
		int segmentStartX = itemBounds.Left + 10;
		int segmentEndX = itemBounds.Right - 10;
		g->DrawLine(hoverPen, segmentStartX, lineY, segmentEndX, lineY);
		delete hoverPen;
	}
	if (currentMenuItem != nullptr) //no else?
	{
		currentMenuItem->ForeColor = Color::LimeGreen;
		Rectangle itemBounds = currentMenuItem->Bounds;
		int segmentStartX = itemBounds.Left + 10;
		int segmentEndX = itemBounds.Right - 10;
		Pen^ currentPen = gcnew Pen(Color::LimeGreen, 2.0f);
		g->DrawLine(currentPen, segmentStartX, lineY, segmentEndX, lineY);
		delete currentPen;
	}	
	delete pen;
}
//before changing the color of the button, the previous button color must be reset
void Form2::MyForm::ResetButtonColors()
{
	for each (ToolStripMenuItem ^ item in MAINBUTTON->Items)
	{
		item->ForeColor = Color::FromArgb(120, Color::White);
	}
}

System::Void Form2::MyForm::TEAMS_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		UC_TEAMS^ ucTeams = gcnew Form2::UC_TEAMS();
		addUserControl(ucTeams);
	}
}
System::Void Form2::MyForm::addUserControl(UserControl^ userControl)
{	
	//why this doesn't check if that's the first time the userControl is added?
	userControl->Dock = DockStyle::Fill;
	this->ContainerPanel->Controls->Clear(); //can this be hidden?
	this->ContainerPanel->Controls->Add(userControl);
	userControl->BringToFront();
}