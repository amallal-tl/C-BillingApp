#pragma once
#include "Utils.h"
#include "connect/HttpSocketManager.h"

namespace Project3CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for NewSalesForm
	/// </summary>
	public ref class NewSalesForm : public System::Windows::Forms::Form
	{
	public:
		NewSalesForm(void)
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
		~NewSalesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ itemNameBox;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ quantityBox;
	private: System::Windows::Forms::TextBox^ amountBox;
	private: System::Windows::Forms::Button^ submitButton;




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
			this->itemNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->quantityBox = (gcnew System::Windows::Forms::TextBox());
			this->amountBox = (gcnew System::Windows::Forms::TextBox());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// itemNameBox
			// 
			this->itemNameBox->Location = System::Drawing::Point(275, 75);
			this->itemNameBox->Name = L"itemNameBox";
			this->itemNameBox->Size = System::Drawing::Size(274, 29);
			this->itemNameBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(153, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Item name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(153, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Quantity";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(153, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Amount";
			// 
			// quantityBox
			// 
			this->quantityBox->Location = System::Drawing::Point(275, 137);
			this->quantityBox->Name = L"quantityBox";
			this->quantityBox->Size = System::Drawing::Size(274, 29);
			this->quantityBox->TabIndex = 4;
			// 
			// amountBox
			// 
			this->amountBox->Location = System::Drawing::Point(275, 202);
			this->amountBox->Name = L"amountBox";
			this->amountBox->Size = System::Drawing::Size(274, 29);
			this->amountBox->TabIndex = 5;
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(427, 275);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(121, 41);
			this->submitButton->TabIndex = 6;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &NewSalesForm::newSaleButton);
			// 
			// NewSalesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 515);
			this->WindowState = FormWindowState::Maximized;
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->amountBox);
			this->Controls->Add(this->quantityBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->itemNameBox);
			this->Name = L"NewSalesForm";
			this->Text = L"NewSalesForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void newSaleButton(System::Object^ sender, System::EventArgs^ e) {
		String^ quantity = quantityBox->Text;
		String^ amount = amountBox->Text;
		String^ itemName = itemNameBox->Text;
		
		if (quantity != nullptr && amount != nullptr && itemName != nullptr) {
			Utils util;
			String^ dateTime = util.get_current_datetime();
			String^ unique_sale_id = amount + dateTime;

			
			System::String^ connectionString = "Data Source=AMALLALTL;" +
				"Initial Catalog=projectclr3;" +
				"Integrated Security=SSPI;";
			SqlConnection^ sqlConn = gcnew SqlConnection(connectionString);
			sqlConn->Open();

			String^ saleInsertQuery = "INSERT INTO [dbo].[sale]([unique_sale_id],[sale_item],[sale_quantity],"+
				"[sale_amount]) VALUES(@unique_sale_id, @sale_item,"+
				"@sale_quantity, @sale_amount)";

			SqlCommand^ command = gcnew SqlCommand(saleInsertQuery, sqlConn);
			command->Parameters->AddWithValue("@unique_sale_id", unique_sale_id);
			command->Parameters->AddWithValue("@sale_item", itemName);
			command->Parameters->AddWithValue("@sale_quantity", quantity);
			command->Parameters->AddWithValue("@sale_amount", amount);
			command->ExecuteNonQuery();
			sqlConn->Close();
			MessageBox::Show("Sale success!");
			this->Close();
		}
	}
};
}
