import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class SalaryLabelGUI {

   public static void main(String[] args) {
      int hourlyWage; 
      int yearlyBonus;            
      JFrame topFrame = null;                // Application window
      JLabel wageLabel = null;               // Label for hourly salary
      JLabel salLabel = null;   			 // Label for yearly salary
      JLabel bonusLabel = null;              // Label for yearly bonus
      JTextField salField = null;            // Displays hourly salary 
      JTextField wageField = null;           // Displays yearly salary
      JTextField bonusField = null;			 // Displays yearly bonus
      GridBagConstraints layoutConst = null; // GUI component layout

      hourlyWage = 20;
      yearlyBonus = 1000;

      // Set hourly and yearly salary
      wageLabel = new JLabel("Hourly wage:");
      salLabel = new JLabel("Yearly salary:");
      bonusLabel = new JLabel("Yearly bonus:");

      wageField = new JTextField(15);
      wageField.setEditable(false);
      wageField.setText(Integer.toString(hourlyWage));

      salField = new JTextField(15);
      salField.setEditable(false);
      salField.setText(Integer.toString((hourlyWage * 40 * 50)));
      
      bonusField = new JTextField(15);
      bonusField.setEditable(false);
      bonusField.setText(Integer.toString(yearlyBonus));

      // Create frame and add components using GridBagLayout
      topFrame = new JFrame("Salary and Shit");
      
      // Use a GridBagLayout
      topFrame.setLayout(new GridBagLayout());

      // Create GridBagConstraints
      layoutConst = new GridBagConstraints();
      
      // Specify component's grid location
      layoutConst.gridx = 0;
      layoutConst.gridy = 0;
      
      // 10 pixels of padding around component
      layoutConst.insets = new Insets(10, 10, 10, 10);
      
      // Add component using the specified constraints
      topFrame.add(wageLabel, layoutConst);

      layoutConst = new GridBagConstraints();
      layoutConst.gridx = 1;
      layoutConst.gridy = 0;
      layoutConst.insets = new Insets(10, 10, 10, 10);
      topFrame.add(wageField, layoutConst);

      layoutConst = new GridBagConstraints();
      layoutConst.gridx = 0;
      layoutConst.gridy = 1;
      layoutConst.insets = new Insets(10, 10, 10, 10);
      topFrame.add(salLabel, layoutConst);

      layoutConst = new GridBagConstraints();
      layoutConst.gridx = 1;
      layoutConst.gridy = 1;
      layoutConst.insets = new Insets(10, 10, 10, 10);
      topFrame.add(salField, layoutConst);
      
      layoutConst = new GridBagConstraints();
      layoutConst.gridx = 0;
      layoutConst.gridy = 2;
      layoutConst.insets = new Insets(10, 10, 10, 10);
      topFrame.add(bonusLabel, layoutConst);
      
      layoutConst = new GridBagConstraints();
      layoutConst.gridx = 1;
      layoutConst.gridy = 2;
      layoutConst.insets = new Insets(10, 10, 10, 10);
      topFrame.add(bonusField, layoutConst);

      // Terminate program when window closes
      topFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
      // Resize window to fit components
      topFrame.pack();
      
      // Display window
      topFrame.setVisible(true);
   }
}
