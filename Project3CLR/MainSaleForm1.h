#pragma once
#include "connect/HttpSocketManager.h"

namespace Project3CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainSaleForm
	/// </summary>
	public ref class MainSaleForm : public System::Windows::Forms::Form
	{
	public:
		MainSaleForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainSaleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel2;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(12, 82);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(788, 322);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(15, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(785, 64);
			this->panel2->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(758, 297);
			this->dataGridView1->TabIndex = 0;
			// 
			// MainSaleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 406);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MainSaleForm";
			this->Text = L"MainSaleForm";
			this->Load += gcnew System::EventHandler(this, &MainSaleForm::formLoad);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void formLoad(System::Object^ sender, System::EventArgs^ e) {
		HttpSocketManager^ socket = HttpSocketManager::GetInstance();
		socket->Connect();

	}
	};
}
