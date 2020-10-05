using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HaatajaGrantAssignment02
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void addCourseButton_Click(object sender, EventArgs e)
        {
            if (courseNumDropdown.GetItemText(this.courseNumDropdown.SelectedItem) == "")
            {
                MessageBox.Show("No course number specified...");
            }
            else if (studentNameDropdown.GetItemText(this.studentNameDropdown.SelectedItem) == "")
            {
                MessageBox.Show("No student specified...");
            }
            else
            {
                MessageBox.Show("Added course " + courseNumDropdown.GetItemText(this.courseNumDropdown.SelectedItem) + " to " + studentNameDropdown.GetItemText(this.studentNameDropdown.SelectedItem) + "'s schedule.\n");
            }
        }

        private void dropCourseButton_Click(object sender, EventArgs e)
        {
            if (courseNumDropdown.GetItemText(this.courseNumDropdown.SelectedItem) == "")
            {
                MessageBox.Show("No course number specified...");
            }
            else if (studentNameDropdown.GetItemText(this.studentNameDropdown.SelectedItem) == "")
            {
                MessageBox.Show("No student specified...");
            }
            else
            {
                MessageBox.Show("Dropped course " + courseNumDropdown.GetItemText(this.courseNumDropdown.SelectedItem) + " from " + studentNameDropdown.GetItemText(this.studentNameDropdown.SelectedItem) + "'s schedule.\n");
            }
        }

        private void displayCourseInfoButton_Click(object sender, EventArgs e)
        {
            if (courseNumDropdown.GetItemText(this.courseNumDropdown.SelectedItem) == "")
            {
                MessageBox.Show("No course number specified...");
            }
            else
            {
                switch (courseNumDropdown.GetItemText(this.courseNumDropdown.SelectedItem))
                {
                    case "CSCI 160":
                        MessageBox.Show("Computer Science 160: Introduction to Computer Programming I\nInstructor: Dr. Thomas Stokke");
                        break;

                    case "CSCI 161":
                        MessageBox.Show("Computer Science 161: Introduction to Computer Programming II\nInstructor: Dr. Thomas Stokke");
                        break;

                    case "CSCI 230":
                        MessageBox.Show("Computer Science 230: System's Programming\nInstructor: Ron Marsh");
                        break;

                    case "CSCI 242":
                        MessageBox.Show("Computer Science 242: Algorithms and Data Structures\nInstructor: Dr. Emanuel Grant");
                        break;

                    case "CSCI 289":
                        MessageBox.Show("Computer Science 289: Social Implications of Computer Technology\nInstructor: Dr. Emanuel Grant");
                        break;

                    case "CSCI 363":
                        MessageBox.Show("Computer Science 363: User Interface Design\nInstructor: Dr. Emanuel Grant");
                        break;

                    case "CSCI 435":
                        MessageBox.Show("Computer Science 435: Formal Languages and Automata\nInstructor: Dr. Marina Kim");
                        break;

                    case "CSCI 451":
                        MessageBox.Show("Computer Science 451: Operating Systems\nInstructor: Ron Marsh");
                        break;

                    case "MATH 207":
                        MessageBox.Show("Mathematics 207: Intro to Linear Algebra\nInstructor: Dr. Bruce Dearden");
                        break;

                    case "MATH 208":
                        MessageBox.Show("Mathematics 208: Discrete Mathematics\nInstructor: Dr. Joel Iiams");
                        break;

                    case "MATH 330":
                        MessageBox.Show("Mathematics 330: Set Theory and Logic\nInstructor: Dr. Lawrence Peterson");
                        break;

                    case "MATH 408":
                        MessageBox.Show("Mathematics 408: Combinatorics\nInstructor: Dr. Jeremiah Bartz");
                        break;

                    case "MATH 441":
                        MessageBox.Show("Mathematics 441: Abstract Algebra\nInstructor: Dr. Joel Iiams");
                        break;

                    case "BIOL 150":
                        MessageBox.Show("Biology 150: General Biology I\nInstructor: Dr. Sally Pyle");
                        break;

                    case "BIOL 151":
                        MessageBox.Show("Biology 151: General Biology II\nInstructor: Dr. Eric Linder");
                        break;

                    case "CHEM 121":
                        MessageBox.Show("Chemistry 121: General Chemistry I\nInstructor: Dr. David Pierce");
                        break;

                    case "CHEM 122":
                        MessageBox.Show("Chemistry 122: General Chemistry II\nInstructor: Dr. Paul Pansegrau");
                        break;

                    default:
                        MessageBox.Show("System Error 148: No course information to display.");
                        break;
                }
            }
        }

        private void displayStudentScheduleButton_Click(object sender, EventArgs e)
        {
            if (studentNameDropdown.GetItemText(this.studentNameDropdown.SelectedItem) == "" && studentIDDropdown.GetItemText(this.studentIDDropdown.SelectedItem) == "")
            {
                MessageBox.Show("No student specified...");
            }
            else
            {
                switch (studentNameDropdown.GetItemText(this.studentNameDropdown.SelectedItem))
                {
                    case "Grant Haataja":
                        MessageBox.Show("Class Schedule for Grant Haataja\nCSCI 451: MWF 10:10am - 11:00am\nCSCI 363: MWF 1:25pm - 2:15pm\nCSCI 435: TuTh 12:15pm - 1:30pm\n");
                        break;

                    case "Robert Stevenson":
                        MessageBox.Show("Class Schedule for Robert Stevenson\nMATH 441: MWF 11:15am - 12:05am\nMATH 208: MWF 1:25pm - 2:15pm\nMATH 207: TuTh 12:15pm - 1:30pm\n");
                        break;

                    case "Charles Dickens":
                        MessageBox.Show("Class Schedule for Charles Dickins\nBIOL 150: MWF 10:10am - 11:00am\nCSCI 363: MWF 1:25pm - 2:15pm\n");
                        break;

                    case "Mark Twain":
                        MessageBox.Show("Class Schedule for Mark Twain\nCSCI 451: MWF 10:10am - 11:00am\nMATH 441: MWF 11:15am - 12:05pm\nMATH 208: MWF 1:25pm - 2:15pm\n");
                        break;

                    case "Jane Eyre":
                        MessageBox.Show("Class Schedule for Jane Eyre\nBIOL 150: MWF 10:10am - 11:00am\nCHEM 121: MWF 1:25pm - 2:15pm\nCSCI 161: TuTh 3:30pm - 4:45pm\n");
                        break;

                    case "James Cooper":
                        MessageBox.Show("Class Schedule for James Cooper\nCSCI 160: MWF 10:10am - 11:00am\nCHEM 121: MWF 1:25pm - 2:15pm\nMATH 207: TuTh 12:15pm - 1:30pm\n");
                        break;

                    default:
                        switch (studentIDDropdown.GetItemText(this.studentIDDropdown.SelectedItem))
                        {
                            case "1019828":
                                MessageBox.Show("Class Schedule for Grant Haataja\nCSCI 451: MWF 10:10am - 11:00am\nCSCI 363: MWF 1:25pm - 2:15pm\nCSCI 435: TuTh 12:15pm - 1:30pm\n");
                                break;

                            case "1019829":
                                MessageBox.Show("Class Schedule for Robert Stevenson\nMATH 441: MWF 11:15am - 12:05am\nMATH 208: MWF 1:25pm - 2:15pm\nMATH 207: TuTh 12:15pm - 1:30pm\n");
                                break;

                            case "1019830":
                                MessageBox.Show("Class Schedule for Charles Dickins\nBIOL 150: MWF 10:10am - 11:00am\nCSCI 363: MWF 1:25pm - 2:15pm\n");
                                break;

                            case "1019831":
                                MessageBox.Show("Class Schedule for Mark Twain\nCSCI 451: MWF 10:10am - 11:00am\nMATH 441: MWF 11:15am - 12:05pm\nMATH 208: MWF 1:25pm - 2:15pm\n");
                                break;

                            case "1019832":
                                MessageBox.Show("Class Schedule for Jane Eyre\nBIOL 150: MWF 10:10am - 11:00am\nCHEM 121: MWF 1:25pm - 2:15pm\nCSCI 161: TuTh 3:30pm - 4:45pm\n");
                                break;

                            case "1019833":
                                MessageBox.Show("Class Schedule for James Cooper\nCSCI 160: MWF 10:10am - 11:00am\nCHEM 121: MWF 1:25pm - 2:15pm\nMATH 207: TuTh 12:15pm - 1:30pm\n");
                                break;

                            default:
                                MessageBox.Show("System Error 149: No schedule information to display for this student.");
                                break;
                        }
                        break;
                }
            }
        }
    }
}
