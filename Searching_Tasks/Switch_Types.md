#  Switches

## Outlines

* ### What is a Switch?

* ### Characteristics of a Switch

* ### Types of Switches

* ### Mechanical Switches

* ### Electronic Switches

_____

### What is a Switch?

* A Switch is a device which is designed to interrupt the current flow in a circuit.
* Every electrical and electronics application uses at least one switch to perform ON and OFF operation of the device.
*  switches are a part of the control system and without it, control operation cannot be achieved.
* A switch can perform two functions, namely fully ON (by closing its contacts) or fully OFF (by opening its contacts).

_____

### Characteristics of a Switch

* The two important characteristics of a switch are its Poles and Throws. A pole represents a contact and a throw represents a contact-to-contact connection. Number of poles and throws are used to describe a switch.
* Some standard numbers of poles and throws are Single (1 pole or 1 throw) and Double (2 poles or 2 switches).
* Another important characteristic of a switch is its action , whether it is a Momentary or Latched action. Momentary Switches (like push buttons, for example) are used to make momentary contact (for a brief time or as long the button is pressed) Latched Switches  maintain the contact until it is forced to the other position.

____

### Types of Switches

 Switches can be of two types. They are:

* Mechanical
* Electronic
  * Mechanical Switches are physical switches, which must be activated physically, by moving, pressing, releasing, or touching its contacts.
  * Electronic Switches, do not require any physical contact in order to control a circuit. These are activated by semiconductor action.

____

### Mechanical Switches

Mechanical switches can be classified into different types based on several factors such as method of actuation (manual, limit and process switches), number of contacts (single contact and multi contact switches), number of poles and throws (SPST, DPDT, SPDT, etc.), operation and construction (push button, toggle, rotary, joystick, etc.), based on state (momentary and locked switches), etc.

* Based on the number of poles and throws, switches are classified into following types. The pole represents the number of individual power circuits that can be switched. Most of the switches are designed have one, two or three poles and are designated as single pole, double pole and triple pole.

* The number of throws represents the number of states to which current can pass through the switch. Most of the switches are designed to have either one or two throws, which are designated as single throw and double throw switches.

  * ##### Single Pole Single Throw Switch (SPST)

    * This is the basic ON and OFF switch consisting of one input contact and one output contact.
    * It switches a single circuit and it can either make (ON) or break (OFF) the load.

  * ##### Single Pole Double Throw Switch (SPDT)

    * This switch has three terminals: one is input contact and remaining two are output contacts.
    * This means it consist two ON positions and one OFF position.
    * In most of the circuits, these switches are used as changeover to connect the input between two choices of outputs.

  * ##### Double Pole Single Throw Switch (DPST)

    * This switch consists of four terminals: two input contacts and two output contacts.
    * It behaves like a two separate SPST configurations, operating at the same time.
    * It has only one ON position, but it can actuate the two contacts simultaneously, such that each input contact will be connected to its corresponding output contact.
    * In OFF position both switches are at open state.
    * This type of switches is used for controlling two different circuits at a time

  * ##### Double Pole Double Throw Switch (DPDT)

    * This is a dual ON/OFF switch consisting of two ON positions.
    * It has six terminals, two are input contacts and remaining four are the output contacts.
    * It behaves like a two separate SPDT configuration, operating at the same time.

  * ##### Push Button Switch

    * It is a momentary contact switch that makes or breaks connection as long as pressure is applied (or when the button is pushed).
    * This button returns its normal position, once the pressure is removed.

  * ##### Toggle Switch

    * A toggle switch is manually actuated (or pushed up or down) by a mechanical handle,These are commonly used as light control switches.
    * Most of these switches come with two or more lever positions which are in the versions of SPDT, SPST, DPST and DPDT switch. 
    * These are used for switching high currents (as high as 10 A) and can also be used for switching small currents.

  * ##### Limit Switch

    * These switches consist of a bumper type of arm actuated by an object. When this bumper arm is actuated, it causes the switch contacts to change position.

  * ##### Float Switches

    * Float switches are mainly used for controlling DC and AC motor pumps according to the liquid or water in a tank or sump.
    * These float switches can be normally open or normally closed type.

  * ##### Flow Switches

    * These are mainly used to detect the movement of liquid or air flow through a pipe or duct.

  * ##### Pressure Switches

    * These switches are commonly used in industrial applications in order to sense the pressure of hydraulic systems and pneumatic devices.

  * ##### Temperature Switches

    * The most common heat sensing element is the bimetallic strip that operates on the principle of thermal expansion.
    * The switch contacts are operated when the temperature causes the strip to bend.

  * ##### Joystick Switch

    * Joystick switches are manually actuated control devices used mainly in portable control equipment.
    * These are used for building machinery, cable controls and cranes

  * ##### Rotary Switches

    * These are used for connecting one line to one of many lines.

  ____

  ### Electronic Switches

  The electronic switches are generally called as Solid State switches because there are no physical moving parts and hence no physical contacts. Most of the appliances are controlled by semiconductor switches such as motor drives and HVAC equipment.

  There are different types of solid state switches are available in todays consumer, industrial and automotive market with different sizes and ratings. Some of these solid state switches include transistors, SCRs, MOSFETs, TRIACs and IGBTs.

  * ##### Bipolar Transistors

    * A transistor either allows the current to pass or it blocks the current 
    * In switching circuits, transistor operates in cut-off mode for OFF or current blocking condition and in saturation mode for ON condition. The active region of the transistor is not used for switching applications.

  * ##### Power Diode

    * A diode can perform switching operations between its high and low state impedance states.
    * Power Diode are constructed using Silicon These are constructed by joining p and n type semiconductor materials together to form PN junction It has two terminals namely anode and cathode.
    * PN junction is forward biased and starts conducting (like ON switch). When the cathode terminal is made positive with respect to anode, PN junction reverse biased and its blocks the current flow (like OFF switch).

  * ##### MOSFET

    * the most popular and most commonly used Semiconductor Switching Device is the MOSFET. Metal Oxide Semiconductor Field Effect Transistor MOSFET is a unipolar and high frequency switching device. It is most commonly used switching device is power electronic applications. It has three terminals namely drain (output), source (common) and gate (input).
    * It is a voltage controlled device , by controlling the input (gate to source) voltage, resistance between the drain and source is controlled, which further determines the ON and OFF state of the device.
    * MOSFETs can be a P-Channel or N-Channel devices. The N-Channel MOSFET is tuned ON by applying a positive VGS with respect to the source (provided that VGS should be greater than threshold voltage).
    * P-channel MOSFET operates in a similar manner of N-channel MOSFET but it uses reverse polarity of voltages. Both VGS and VDD are negative with respect to the source to switch ON the P-channel MOSFET.

  * ##### IGBT

    * IGBT (Insulated Gate Bipolar Transistor) combines the several advantages of bipolar junction power transistor and power MOSFET. Like a MOSFET, it is a voltage controlled device and has lower ON state voltage drop (less than that of MOSFET and closer to power transistor).

      It is a three terminal semiconductor high speed switching device. These terminals are emitter, collector and gate.

    * Similar to the MOSFET, IGBT can be turned ON by applying a positive voltage (greater than the threshold voltage) between the gate and emitter. IGBT can be turned OFF by reducing the voltage across the gate-emitter to zero. In most of the cases, it needs a negative voltage to reduce the turn OFF losses and safely turn OFF the IGBT.

  * ##### SCR

    * A Silicon Controlled Rectifier(SCR)is one of the most widely used high speed switching device for power control applications. It is a unidirectional device as a diode, consisting of three terminals, namely anode, cathode and gate.

      An SCR is turned ON and OFF by controlling its gate input and biasing conditions of the anode and cathode terminals. SCR consists of four layers of alternate P and N layers such that boundaries of each layer forms junctions J1, J2 and J3.

  * ##### TRIAC

    * TRIAC (or **TRI**ode **AC**) switch is a bidirectional switching device, which is an equivalent circuit of two back to back SCRs connection with one gate terminal.
    * Its capability to control AC power in both positive and negative peaks of the voltage waveform often makes these devices to be used in motor speed controllers, light dimmers, pressure control systems, motor drives and other AC control equipment.

  * ##### DIAC

    * DIAC  (or **DI**ode **AC** Switch) is bidirectional switching device and it consists of two terminals, which are not named as anode and cathode as it is a bidirectional device i.e., a DIAC can be operated in either direction regardless of the terminal identification. This indicates that the DIAC can be used in either direction.
    * When a voltage is applied across a DIAC, it either operates in forward blocking or reverse blocking mode unless the applied voltage is less than the breakover voltage. Once the voltage is increased more than breakover voltage, avalanche breakover occurs and device starts conducting.

  * ##### Gate Turn-Off Thyristor

    * A GTO(Gate Turn-Off Thyristor) is a bipolar semiconductor switching device. It has three terminals: an anode, a cathode and a gate. As the name implies, this switching device is capable to turn OFF through gate terminal.
    * A GTO is turned ON by applying a small positive gate current, which triggers the conduction mode. It can be turned OFF by a negative pulse to the gate. GTO symbol consists of double arrows on the gate terminal, which represents the bidirectional flow of current through gate terminal.

  _____

  > Aya Ramadan

  

  