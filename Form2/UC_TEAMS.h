#pragma once
#include "resource.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace Form2 {

	/// <summary>
	/// Summary for UC_TEAMS
	/// </summary>
	public ref class UC_TEAMS : public System::Windows::Forms::UserControl
	{
	public:
		UC_TEAMS(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			defaultImages = gcnew Dictionary<Button^, Bitmap^>();
			hoverImages = gcnew Dictionary<Button^, Bitmap^>();

			for each (Control ^ ctrl in tableLayoutPanel1->Controls)
			{
				Button^ button = dynamic_cast<Button^>(ctrl);
				if (button != nullptr)
				{
					String^ defaultImageName = button->Name + "_Default";
					String^ hoverImageName = button->Name + "_Hover";

					Bitmap^ defaultImage = safe_cast<Bitmap^>(Resources::ResourceManager::GetObject(defaultImageName));



				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UC_TEAMS()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: Dictionary<Button^, Bitmap^>^ defaultImages;
	private: Dictionary<Button^, Bitmap^>^ hoverImages;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->button4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->button5, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->button6, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button7, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->button8, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->button9, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->button10, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->button11, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->button12, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->button13, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->button14, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->button15, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->button16, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->button17, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->button18, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->button19, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->button20, 4, 3);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(992, 661);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(192, 159);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UC_TEAMS::button1_Click_1);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->Location = System::Drawing::Point(201, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(192, 159);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UC_TEAMS::button2_Click_1);
			// 
			// button3
			// 
			this->button3->AutoSize = true;
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Location = System::Drawing::Point(399, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(192, 159);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &UC_TEAMS::button3_Click_1);
			// 
			// button4
			// 
			this->button4->AutoSize = true;
			this->button4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button4->Location = System::Drawing::Point(597, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(192, 159);
			this->button4->TabIndex = 3;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &UC_TEAMS::button4_Click_1);
			// 
			// button5
			// 
			this->button5->AutoSize = true;
			this->button5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button5->Location = System::Drawing::Point(795, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(194, 159);
			this->button5->TabIndex = 4;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &UC_TEAMS::button5_Click_1);
			// 
			// button6
			// 
			this->button6->AutoSize = true;
			this->button6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button6->Location = System::Drawing::Point(3, 168);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(192, 159);
			this->button6->TabIndex = 5;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &UC_TEAMS::button6_Click_1);
			// 
			// button7
			// 
			this->button7->AutoSize = true;
			this->button7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button7->Location = System::Drawing::Point(201, 168);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(192, 159);
			this->button7->TabIndex = 6;
			this->button7->Text = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &UC_TEAMS::button7_Click_1);
			// 
			// button8
			// 
			this->button8->AutoSize = true;
			this->button8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button8->Location = System::Drawing::Point(399, 168);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(192, 159);
			this->button8->TabIndex = 7;
			this->button8->Text = L"button8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &UC_TEAMS::button8_Click_1);
			// 
			// button9
			// 
			this->button9->AutoSize = true;
			this->button9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button9->Location = System::Drawing::Point(597, 168);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(192, 159);
			this->button9->TabIndex = 8;
			this->button9->Text = L"button9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &UC_TEAMS::button9_Click_1);
			// 
			// button10
			// 
			this->button10->AutoSize = true;
			this->button10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button10->Location = System::Drawing::Point(795, 168);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(194, 159);
			this->button10->TabIndex = 9;
			this->button10->Text = L"button10";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &UC_TEAMS::button10_Click_1);
			// 
			// button11
			// 
			this->button11->AutoSize = true;
			this->button11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button11->Location = System::Drawing::Point(3, 333);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(192, 159);
			this->button11->TabIndex = 10;
			this->button11->Text = L"button11";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &UC_TEAMS::button11_Click_1);
			// 
			// button12
			// 
			this->button12->AutoSize = true;
			this->button12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button12->Location = System::Drawing::Point(201, 333);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(192, 159);
			this->button12->TabIndex = 11;
			this->button12->Text = L"button12";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &UC_TEAMS::button12_Click_1);
			// 
			// button13
			// 
			this->button13->AutoSize = true;
			this->button13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button13->Location = System::Drawing::Point(399, 333);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(192, 159);
			this->button13->TabIndex = 12;
			this->button13->Text = L"button13";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &UC_TEAMS::button13_Click_1);
			// 
			// button14
			// 
			this->button14->AutoSize = true;
			this->button14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button14->Location = System::Drawing::Point(597, 333);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(192, 159);
			this->button14->TabIndex = 13;
			this->button14->Text = L"button14";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &UC_TEAMS::button14_Click_1);
			// 
			// button15
			// 
			this->button15->AutoSize = true;
			this->button15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button15->Location = System::Drawing::Point(795, 333);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(194, 159);
			this->button15->TabIndex = 14;
			this->button15->Text = L"button15";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &UC_TEAMS::button15_Click_1);
			// 
			// button16
			// 
			this->button16->AutoSize = true;
			this->button16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button16->Location = System::Drawing::Point(3, 498);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(192, 160);
			this->button16->TabIndex = 15;
			this->button16->Text = L"button16";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &UC_TEAMS::button16_Click_1);
			// 
			// button17
			// 
			this->button17->AutoSize = true;
			this->button17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button17->Location = System::Drawing::Point(201, 498);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(192, 160);
			this->button17->TabIndex = 16;
			this->button17->Text = L"button17";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &UC_TEAMS::button17_Click_1);
			// 
			// button18
			// 
			this->button18->AutoSize = true;
			this->button18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button18->Location = System::Drawing::Point(399, 498);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(192, 160);
			this->button18->TabIndex = 17;
			this->button18->Text = L"button18";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &UC_TEAMS::button18_Click_1);
			// 
			// button19
			// 
			this->button19->AutoSize = true;
			this->button19->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button19->Location = System::Drawing::Point(597, 498);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(192, 160);
			this->button19->TabIndex = 18;
			this->button19->Text = L"button19";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &UC_TEAMS::button19_Click_1);
			// 
			// button20
			// 
			this->button20->AutoSize = true;
			this->button20->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button20->Location = System::Drawing::Point(795, 498);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(194, 160);
			this->button20->TabIndex = 19;
			this->button20->Text = L"button20";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &UC_TEAMS::button20_Click_1);
			// 
			// UC_TEAMS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"UC_TEAMS";
			this->Size = System::Drawing::Size(992, 661);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button10_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button15_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button9_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button11_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button12_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button13_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button14_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button16_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button17_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button18_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button19_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button20_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
