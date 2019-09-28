#pragma once
#include "RutaCarrera.h"
#include <iostream>

namespace Lab2DiegoMorales1132119 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		static int segundos = 0;
		static int minutos = 0;
		String^ seg;
		String^ min;
		
		int *Tortuga, *Liebre;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Panel^ panel1;
 
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
	private: System::Windows::Forms::Button^ btnCarrera;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnCarrera = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// btnCarrera
			// 
			this->btnCarrera->Location = System::Drawing::Point(12, 66);
			this->btnCarrera->Name = L"btnCarrera";
			this->btnCarrera->Size = System::Drawing::Size(94, 27);
			this->btnCarrera->TabIndex = 0;
			this->btnCarrera->Text = L"Empezar carrera";
			this->btnCarrera->UseVisualStyleBackColor = true;
			this->btnCarrera->Click += gcnew System::EventHandler(this, &MyForm::BtnCarrera_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 143);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Tiempo: 0:0";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(112, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(272, 243);
			this->panel1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(396, 342);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCarrera);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnCarrera_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::MessageBox::Show("¡BANG!");
		System::Windows::Forms::MessageBox::Show("¡Y ARRANCAN!");
		timer1->Start();
	}
	private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		segundos++;

		if (segundos == 61) {
			segundos = 0;
			minutos++;
		}
		seg = Convert::ToString(segundos);
		min = Convert::ToString(minutos);
		label1->Text = "Tiempo: "+ min + ":" + seg;
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Stop();
		int Ruta[70];
		int MovsTortuga[10] = { 3,3,3,3,3,-6,-6,1,1,1 };
		int MovsLiebre[10] = { 0,0,9,9,-12,1,1,1,-2,-2 };
		int *Tortuga, *Liebre;
		
		Tortuga = Liebre = &Ruta[0];
		for (int i = 0; i < 70; i++)
		{
			Ruta[i] = i + 1;
		}

		RutaCarrera *PosT = new RutaCarrera();
		RutaCarrera *PosL = new RutaCarrera();
		bool gano = false;
		while (gano = false)
		{
			&PosT->CambiarPosicion(Ruta, MovsTortuga, &Tortuga);
			&PosL->CambiarPosicion(Ruta, MovsLiebre, &Liebre);
			for (int j = 0; j < 70; j++)
			{
				if (&PosT == &PosL && Tortuga == &Ruta[j])
				{
					System::Windows::Forms::MessageBox::Show("¡OUCH!");
				}
				else if (Tortuga == &Ruta[j])
				{
					Ruta[*Tortuga] = char("T");
				}
				else if (Liebre == &Ruta[j])
				{
					Ruta[*Liebre] = char("H");
				}
				else
				{
					Ruta[j] = char("_");
				}
			}

			if (Tortuga == &Ruta[69])
			{
				System::Windows::Forms::MessageBox::Show("¡LA TORTUGA GANA! ¡BRAVO!");
				gano = true;
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("La liebre gana.Ni hablar");
				gano = true;
			}
		}

		panel1->Text = System::Convert::ToString(Ruta);
}
};
}