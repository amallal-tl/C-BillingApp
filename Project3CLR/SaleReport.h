#pragma once

#include "NewSalesForm.h"

namespace Project3CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for SaleReport
	/// </summary>
	public ref class SaleReport : public System::Windows::Forms::Form
	{
	public:
		SaleReport(void)
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
		~SaleReport()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridView^ currentSaleGridView;

	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->currentSaleGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentSaleGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 14);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(231, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"New Sale";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SaleReport::newSaleClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(270, 14);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(231, 40);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Store";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(508, 14);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(231, 40);
			this->button3->TabIndex = 3;
			this->button3->Text = L"New Order";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(2008, 26);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(106, 41);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Refresh";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &SaleReport::refershBut);
			// 
			// currentSaleGridView
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->currentSaleGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->currentSaleGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->currentSaleGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->currentSaleGridView->Location = System::Drawing::Point(32, 77);
			this->currentSaleGridView->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->currentSaleGridView->Name = L"currentSaleGridView";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->currentSaleGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->currentSaleGridView->RowHeadersWidth = 62;
			this->currentSaleGridView->RowTemplate->Height = 28;
			this->currentSaleGridView->Size = System::Drawing::Size(2095, 664);
			this->currentSaleGridView->TabIndex = 5;
			// 
			// SaleReport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2167, 811);
			this->Controls->Add(this->currentSaleGridView);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"SaleReport";
			this->Text = L"SaleReport";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentSaleGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void refershBut(System::Object^ sender, System::EventArgs^ e) {
		System::String^ connectionString = "Data Source=AMALLALTL;" +
			"Initial Catalog=projectclr3;" +
			"Integrated Security=SSPI;";
		try {
			SqlConnection sqlConn(connectionString);
			sqlConn.Open();

			System::String^ sqlQuery = "SELECT [sale_id],[sale_item],[sale_quantity],[sale_amount],[remaining_in_store] FROM[dbo].[sale]";
			SqlCommand command(sqlQuery, % sqlConn);

			SqlDataAdapter^ sda = gcnew SqlDataAdapter(%command);

			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);

			BindingSource^ bsource = gcnew BindingSource();
			bsource->DataSource = dbdataset;

			currentSaleGridView->DataSource = bsource;
			sda->Update(dbdataset);

			sqlConn.Close();

			//SqlDataReader^ read = command.ExecuteReader();
			
		}
		catch (System::Exception^ e) {

		}
	}
	private: System::Void newSaleClick(System::Object^ sender, System::EventArgs^ e) {
		NewSalesForm newSaleForm;
		newSaleForm.ShowDialog();
	}
};
}
