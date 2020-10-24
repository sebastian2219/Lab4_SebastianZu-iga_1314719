#pragma once
#include "Lista.h"
#include "Nodo.h"
#include "Ordenamiento.h";

namespace Lab4SebastianZuñiga1314719 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(66, 59);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(48, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"CargarArchivo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(347, 87);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Ordenamiento Burbuja";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(347, 116);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(141, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Ordenaminto Rapido";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(347, 145);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(141, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Ordenaminto Estupido";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 251);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Tiempo: ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(574, 313);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			Lista^ lisPais = gcnew Lista();
			Lista^ lisAño = gcnew Lista();
			Lista^ lisNum = gcnew Lista();

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Lista^ lis = gcnew Lista();
	Lista^ lis2 = gcnew Lista();
	String^ Lvalue;
	try
	{
		OpenFileDialog dialogoLectura;
		if (dialogoLectura.ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			StreamReader^ reader = gcnew StreamReader(dialogoLectura.FileName);
			while (reader->Peek() >= 0)
			{
				String^ line = reader->ReadToEnd();
				for (int i = 0; i < line->Split('\n')->Length; i++) {
					
					Lvalue = line->Split('\n')[i];
					lis->PushS(Lvalue);
				}

			}
		}
		
	}
	catch (...)
	{

	}
	array<String^>^ Valores = gcnew array<String^>(3);
	for (int i = 0; i < lis->Length; i++) {
		String^ DComa = lis->Pop();
		Valores = DComa->Split(',');
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) {
				String^ Depa = Valores[j];
				lisPais->PushS(Depa);
			}
			else if (j == 1) {
				String^ Anio = Valores[j];
				lisAño->PushS(Anio);
			}
			else
			{
				int Num = int::Parse(Valores[j]);
				lisNum->Push(Num);
			}
		}
	}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Ordenamiento^ ORD = gcnew Ordenamiento();
	ORD->BurbujaOpe(lisNum);
	lisNum->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Ordenamiento^ ORD = gcnew Ordenamiento();
	ORD->StupidOpe(lisNum);
	lisNum->Show();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
 