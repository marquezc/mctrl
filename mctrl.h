/* mctrl.h - Motor Control Header File */

/* -------------------------------------------------------------------------- */
/*  MCTRL General -------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

#define ON 1
#define OFF 0

/* -------------------------------------------------------------------------- */
/*  MCTRL Node -------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_connect()
   Connect the movement control node (MCTRL) to the 
   master control unit (MCU).  */

/* mctrl_connection_status()
   Return the connection status of the MCTRL node. */

/* -------------------------------------------------------------------------- */
/*  MCTRL Interface --------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_interface_en()
   Enable/Disable the MCTRL interface. */

/* mctrl_interface_status()
   Return the status of the MCTRL interface.

/* -------------------------------------------------------------------------- */
/*  MCTRL Device Network ---------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_devnet_new()
   Create a new control network for movement system */

/* mctrl_devnet_link()
   Link the specified control network to the MCTRL
   interface. */

/* mctrl_devnet_status()
   Return status information for the linked control network */

/* mctrl_devnet_add()
   Add a movement device to the specified control network */

/* mctrl_devnet_del()
   Remove the specified movement device from the specified 
   control network */

/* mctrl_devnet_en()
   Enable/Disable all movement devices on the specified
   control network */

/* mctrl_devnet_dev_status()
   Return status information for all movement devices
   on the specified control network */

/* -------------------------------------------------------------------------- */
/*  MCTRL Device ------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */

/* mctrl_dev_en()
   Enable/Disable the specified movement device.

/* mctrl_dev_status()
   Return the status of the specified movement devices. */

/* -------------------------------------------------------------------------- */
/*  MCTRL Positioning ------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_poslr_check()
   Return the left/right position of the system (e.g. mount) */

/* mctrl_poslr_cal()
   Calibrate the left/right positioning of the system */

/* mctrl_poslr_swingl()
   Swing the system left by the specified amount */
   
/* mctrl_poslr_swingr()
   Swing the system right by the specified amount*/

/* mctrl_posud_check()
   Return the up/down position of the system (e.g. mount) */

/* mctrl_posud_cal()
   Calibrate the up/down positioning of the system */

/* mctrl_posud_moveu
   Move the system up by the specified amount */

/* mctrl_posud_moved
   Move the system down by the specified amount */

/* -------------------------------------------------------------------------- */
/*  MCTRL Function Check ---------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_ibit()
   Perform a function check for the movement system */

   
