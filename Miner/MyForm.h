#pragma once
namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   const float BORDER = 20;
	protected:

	private:
		System::ComponentModel::Container^ components;

		void DrawField(Graphics^ graphics) {

			Pen^ pen = gcnew Pen(Color::Black);
			pen->Width = 1;

			float width = pictureBox1->Width - 2 *  BORDER;
			float height = pictureBox1->Height -2 *  BORDER;


			Rectangle^ rectangle = gcnew Rectangle(BORDER, BORDER, width, height);

			graphics->DrawRectangle(pen, *rectangle);

			float cellWidth = width / 8;
			float cellHeight = height / 8;

			float cellProgressWidth = BORDER;
			for (float i = 0; i < 7; i++) {
				cellProgressWidth += cellWidth;
				graphics->DrawLine(pen, cellProgressWidth, BORDER, cellProgressWidth, height + BORDER);
			}

			float cellProgressHeight = BORDER;
			for (float i = 0; i < 7; i++) {
				cellProgressHeight += cellHeight;
				graphics->DrawLine(pen, BORDER, cellProgressHeight, width + BORDER, cellProgressHeight);
			}
		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(477, 398);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 422);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Width = this->Width - 2 * BORDER;
		pictureBox1->Height = this->Height - 2 * BORDER;
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		DrawField(e->Graphics);
		pictureBox1->Refresh();
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Width = this->Width - 2 * BORDER;
		pictureBox1->Height = this->Height - 2 * BORDER;
		pictureBox1->Refresh();

	}
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		//this->Text = e->X + " " + e->Y;
		
		
	}
};
}
