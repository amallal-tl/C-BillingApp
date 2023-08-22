#pragma once
#include "Utils.h"

namespace Project3CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StoreForm
	/// </summary>
	public ref class StoreForm : public System::Windows::Forms::Form
	{
	public:
		StoreForm(void)
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
		~StoreForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ addNewItemButton;
	private: System::Windows::Forms::DataGridView^ storeGridView;
	private: System::Windows::Forms::Button^ refreshButton;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->addNewItemButton = (gcnew System::Windows::Forms::Button());
			this->storeGridView = (gcnew System::Windows::Forms::DataGridView());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->storeGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// addNewItemButton
			// 
			this->addNewItemButton->Location = System::Drawing::Point(26, 26);
			this->addNewItemButton->Name = L"addNewItemButton";
			this->addNewItemButton->Size = System::Drawing::Size(259, 48);
			this->addNewItemButton->TabIndex = 0;
			this->addNewItemButton->Text = L"Add New Item To Store";
			this->addNewItemButton->UseVisualStyleBackColor = true;
			// 
			// storeGridView
			// 
			this->storeGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->storeGridView->Location = System::Drawing::Point(26, 112);
			this->storeGridView->Name = L"storeGridView";
			this->storeGridView->RowHeadersWidth = 72;
			this->storeGridView->RowTemplate->Height = 31;
			this->storeGridView->Size = System::Drawing::Size(890, 392);
			this->storeGridView->TabIndex = 1;
			// 
			// refreshButton
			// 
			this->refreshButton->Location = System::Drawing::Point(1000, 26);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(159, 48);
			this->refreshButton->TabIndex = 2;
			this->refreshButton->Text = L"Refresh";
			this->refreshButton->UseVisualStyleBackColor = true;
			this->refreshButton->Click += gcnew System::EventHandler(this, &StoreForm::refreshStoreTable);
			// 
			// StoreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1196, 543);
			this->Controls->Add(this->refreshButton);
			this->Controls->Add(this->storeGridView);
			this->Controls->Add(this->addNewItemButton);
			this->Name = L"StoreForm";
			this->Text = L"StoreForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->storeGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void refreshStoreTable(System::Object^ sender, System::EventArgs^ e) {
		System::String^ connectionString = "Data Source=AMALLALTL;" +
			"Initial Catalog=projectclr3;" +
			"Integrated Security=SSPI;";
		try {
			SqlConnection sqlConn(connectionString);
			sqlConn.Open();

			System::String^ sqlQuery = "SELECT [unique_sale_id],[sale_item],[sale_quantity],[sale_amount]" +
				"FROM[dbo].[sale]";
			SqlCommand command(sqlQuery, % sqlConn);

			SqlDataAdapter^ sda = gcnew SqlDataAdapter(% command);

			DataTable^ dbdataset = gcnew DataTable();
			int status = sda->Fill(dbdataset);

			BindingSource^ bsource = gcnew BindingSource();
			bsource->DataSource = dbdataset;

			storeGridView->DataSource = bsource;
			sda->Update(dbdataset);

			sqlConn.Close();
		}
		catch (System::Exception^ e) {
			MessageBox::Show("Error occured!");
		}

	}
	};
}
