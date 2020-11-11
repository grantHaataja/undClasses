using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HaatajaGrantAssignment04
{
    public partial class Form1 : Form
    {
        float principal;
        float interestRate;
        float loanPeriod;
        float monthlyPayment;
        ToolTip tool1 = new ToolTip();
        ToolTip tool2 = new ToolTip();
        ToolTip tool3 = new ToolTip();
        ToolTip tool4 = new ToolTip();

        public Form1()
        {
            InitializeComponent();

            tool1.SetToolTip(this.textBox1, "Enter the Principal loan amount in dollars");
            tool2.SetToolTip(this.textBox4, "Enter the annual loan interest as a fraction, i.e. 0.0785");
            tool3.SetToolTip(this.textBox2, "Enter the loan period in years");
            tool4.SetToolTip(this.textBox3, "Enter the monthly payment in dollars");
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        //Loan Amount
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        //Loan Interest
        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        //Loan Period
        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        //Monthly Payment
        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        //Submit
        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "" || textBox4.Text == "")
            {
                MessageBox.Show("Please input both the loan amount and loan interest.");
            }
            else if (textBox2.Text == "" && textBox3.Text == "")
            {
                MessageBox.Show("Please input either the loan period or the monthly repayment amount.");
            }
            //solve for loan period
            else if (textBox2.Text == "")
            {
                //get inputs from text boxes
                try
                {
                    principal = float.Parse(textBox1.Text);
                    interestRate = float.Parse(textBox4.Text);
                    //loanPeriod = float.Parse(textBox2.Text);
                    monthlyPayment = float.Parse(textBox3.Text);
                } catch (FormatException err)
                {
                    if (err.Source != null)
                    {
                        MessageBox.Show("Please enter valid numbers as inputs.");
                        Debug.WriteLine("Format Exception: ", err.Source);
                    }
                }
                
                //validate inputs are reasonable numbers
                if (principal <= 0)
                {
                    MessageBox.Show("Loan Amount must be greater than zero.");
                }
                else if (interestRate < 0 || interestRate > 1)
                {
                    if (interestRate < 100 && interestRate > 1)
                    {
                        interestRate /= 100.0f;
                    }
                    else
                    {
                    MessageBox.Show("Interest Rate must be between 0 and 1.");
                    }
                }
                else if (monthlyPayment > principal)
                {
                    MessageBox.Show("Monthly Payment cannot exceed Loan Amount.");
                }
                else if (monthlyPayment < 1)
                {
                    MessageBox.Show("Monthly Payment is too low to perform calculation.");
                }
                else
                {
                    //perform calcuations
                    float yearlyPayment = monthlyPayment * 12.0f;
                    float yearlyInterest = interestRate * principal;
                    float temp = yearlyPayment - yearlyInterest;
                    loanPeriod = principal / temp;

                    if (loanPeriod >= 1)
                    {
                        MessageBox.Show("The loan period is " + loanPeriod + " years.");
                    }
                    else if (loanPeriod < 1)
                    {
                        loanPeriod *= 12.0f;
                        MessageBox.Show("The loan period is " + loanPeriod + " months.");
                    }
                } 
            }
            //solve for monthly payment
            else if (textBox3.Text == "")
            {
                //get inputs from text boxes
                try
                {
                    principal = float.Parse(textBox1.Text);
                    interestRate = float.Parse(textBox4.Text);
                    loanPeriod = float.Parse(textBox2.Text);
                    //monthlyPayment = float.Parse(textBox3.Text);
                }
                catch (FormatException err)
                {
                    if (err.Source != null)
                    {
                        MessageBox.Show("Please enter valid numbers as inputs.");
                        Debug.WriteLine("Format Exception: ", err.Source);
                    }
                }

                //validate inputs are reasonable numbers
                if (principal <= 0)
                {
                    MessageBox.Show("Loan Amount must be greater than zero.");
                }
                else if (interestRate < 0 || interestRate > 1)
                {
                    if (interestRate < 100 && interestRate > 1)
                    {
                        interestRate /= 100.0f;
                    }
                    else
                    {
                        MessageBox.Show("Interest Rate must be between 0 and 1.");
                    }
                }
                else if (loanPeriod <= 0)
                {
                    MessageBox.Show("Load Period cannot be less than or equal to zero.");
                }
                else
                {
                    //perform calcuations
                    float totalAmount = principal * (1 + (interestRate * loanPeriod));
                    float months = loanPeriod * 12.0f;
                    monthlyPayment = totalAmount / months;

                    MessageBox.Show("The monthly payment is: $" + monthlyPayment);
                }
            }
            else
            {
                MessageBox.Show("Please enter either loand period or monthly payment. Leave one of those fields blank in order to perform a claculation.");
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void toolTip1_Popup(object sender, PopupEventArgs e)
        {
            toolTip1.Show("Tooltip Text", textBox1);
        }
    }
}
