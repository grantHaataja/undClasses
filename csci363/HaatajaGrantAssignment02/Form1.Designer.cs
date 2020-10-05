namespace HaatajaGrantAssignment02
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.addCourseButton = new System.Windows.Forms.Button();
            this.dropCourseButton = new System.Windows.Forms.Button();
            this.displayCourseButton = new System.Windows.Forms.Button();
            this.displayScheduleButton = new System.Windows.Forms.Button();
            this.title = new System.Windows.Forms.Label();
            this.studentIDDropdown = new System.Windows.Forms.ComboBox();
            this.studentNameDropdown = new System.Windows.Forms.ComboBox();
            this.departmentDropdown = new System.Windows.Forms.ComboBox();
            this.courseNumDropdown = new System.Windows.Forms.ComboBox();
            this.studentIDLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // addCourseButton
            // 
            this.addCourseButton.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.addCourseButton.Location = new System.Drawing.Point(49, 93);
            this.addCourseButton.Name = "addCourseButton";
            this.addCourseButton.Size = new System.Drawing.Size(91, 24);
            this.addCourseButton.TabIndex = 0;
            this.addCourseButton.Text = "Add a course";
            this.addCourseButton.UseVisualStyleBackColor = false;
            this.addCourseButton.Click += new System.EventHandler(this.addCourseButton_Click);
            // 
            // dropCourseButton
            // 
            this.dropCourseButton.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.dropCourseButton.Location = new System.Drawing.Point(49, 132);
            this.dropCourseButton.Name = "dropCourseButton";
            this.dropCourseButton.Size = new System.Drawing.Size(91, 24);
            this.dropCourseButton.TabIndex = 0;
            this.dropCourseButton.Text = "Drop a course";
            this.dropCourseButton.UseVisualStyleBackColor = false;
            this.dropCourseButton.Click += new System.EventHandler(this.dropCourseButton_Click);
            // 
            // displayCourseButton
            // 
            this.displayCourseButton.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.displayCourseButton.Location = new System.Drawing.Point(49, 172);
            this.displayCourseButton.Name = "displayCourseButton";
            this.displayCourseButton.Size = new System.Drawing.Size(175, 24);
            this.displayCourseButton.TabIndex = 0;
            this.displayCourseButton.Text = "Display course information";
            this.displayCourseButton.UseVisualStyleBackColor = false;
            this.displayCourseButton.Click += new System.EventHandler(this.displayCourseInfoButton_Click);
            // 
            // displayScheduleButton
            // 
            this.displayScheduleButton.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.displayScheduleButton.Location = new System.Drawing.Point(49, 212);
            this.displayScheduleButton.Name = "displayScheduleButton";
            this.displayScheduleButton.Size = new System.Drawing.Size(175, 24);
            this.displayScheduleButton.TabIndex = 0;
            this.displayScheduleButton.Text = "Display student schedule";
            this.displayScheduleButton.UseVisualStyleBackColor = false;
            this.displayScheduleButton.Click += new System.EventHandler(this.displayStudentScheduleButton_Click);
            // 
            // title
            // 
            this.title.AutoSize = true;
            this.title.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.title.Location = new System.Drawing.Point(209, 29);
            this.title.Name = "title";
            this.title.Size = new System.Drawing.Size(170, 25);
            this.title.TabIndex = 1;
            this.title.Text = "Registrar\'s Helper";
            this.title.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // studentIDDropdown
            // 
            this.studentIDDropdown.AllowDrop = true;
            this.studentIDDropdown.FormattingEnabled = true;
            this.studentIDDropdown.Items.AddRange(new object[] {
            "1019828",
            "1019829",
            "1019830",
            "1019831",
            "1019832",
            "1019833"});
            this.studentIDDropdown.Location = new System.Drawing.Point(405, 93);
            this.studentIDDropdown.MaxDropDownItems = 18;
            this.studentIDDropdown.Name = "studentIDDropdown";
            this.studentIDDropdown.Size = new System.Drawing.Size(142, 23);
            this.studentIDDropdown.TabIndex = 2;
            // 
            // studentNameDropdown
            // 
            this.studentNameDropdown.FormattingEnabled = true;
            this.studentNameDropdown.Items.AddRange(new object[] {
            "Grant Haataja",
            "Robert Stevenson",
            "Charles Dickens",
            "Mark Twain",
            "Jane Eyre",
            "James Cooper"});
            this.studentNameDropdown.Location = new System.Drawing.Point(405, 132);
            this.studentNameDropdown.MaxDropDownItems = 18;
            this.studentNameDropdown.Name = "studentNameDropdown";
            this.studentNameDropdown.Size = new System.Drawing.Size(142, 23);
            this.studentNameDropdown.TabIndex = 2;
            // 
            // departmentDropdown
            // 
            this.departmentDropdown.FormattingEnabled = true;
            this.departmentDropdown.Items.AddRange(new object[] {
            "Computer Science",
            "Mathematics",
            "Biology",
            "Chemistry"});
            this.departmentDropdown.Location = new System.Drawing.Point(405, 172);
            this.departmentDropdown.Name = "departmentDropdown";
            this.departmentDropdown.Size = new System.Drawing.Size(142, 23);
            this.departmentDropdown.TabIndex = 2;
            // 
            // courseNumDropdown
            // 
            this.courseNumDropdown.FormattingEnabled = true;
            this.courseNumDropdown.Items.AddRange(new object[] {
            "CSCI 160",
            "CSCI 161",
            "CSCI 230",
            "CSCI 242",
            "CSCI 289",
            "CSCI 363",
            "CSCI 435",
            "CSCI 451",
            "MATH 207",
            "MATH 208",
            "MATH 330",
            "MATH 408",
            "MATH 441",
            "BIOL 150",
            "BIOL 151",
            "CHEM 121",
            "CHEM 122"});
            this.courseNumDropdown.Location = new System.Drawing.Point(405, 212);
            this.courseNumDropdown.MaxDropDownItems = 28;
            this.courseNumDropdown.Name = "courseNumDropdown";
            this.courseNumDropdown.Size = new System.Drawing.Size(142, 23);
            this.courseNumDropdown.TabIndex = 2;
            // 
            // studentIDLabel
            // 
            this.studentIDLabel.AutoSize = true;
            this.studentIDLabel.Location = new System.Drawing.Point(334, 98);
            this.studentIDLabel.Name = "studentIDLabel";
            this.studentIDLabel.Size = new System.Drawing.Size(65, 15);
            this.studentIDLabel.TabIndex = 3;
            this.studentIDLabel.Text = "Student ID:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(313, 137);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 15);
            this.label3.TabIndex = 3;
            this.label3.Text = "Student Name:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(326, 175);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(73, 15);
            this.label4.TabIndex = 3;
            this.label4.Text = "Department:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(305, 217);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(94, 15);
            this.label5.TabIndex = 3;
            this.label5.Text = "Course Number:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(582, 336);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.studentIDLabel);
            this.Controls.Add(this.courseNumDropdown);
            this.Controls.Add(this.departmentDropdown);
            this.Controls.Add(this.studentNameDropdown);
            this.Controls.Add(this.studentIDDropdown);
            this.Controls.Add(this.title);
            this.Controls.Add(this.displayScheduleButton);
            this.Controls.Add(this.displayCourseButton);
            this.Controls.Add(this.dropCourseButton);
            this.Controls.Add(this.addCourseButton);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button addCourseButton;
        private System.Windows.Forms.Button dropCourseButton;
        private System.Windows.Forms.Button displayCourseButton;
        private System.Windows.Forms.Button displayScheduleButton;
        private System.Windows.Forms.Label title;
        private System.Windows.Forms.ComboBox studentIDDropdown;
        private System.Windows.Forms.ComboBox studentNameDropdown;
        private System.Windows.Forms.ComboBox departmentDropdown;
        private System.Windows.Forms.ComboBox courseNumDropdown;
        private System.Windows.Forms.Label studentIDLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
    }
}

