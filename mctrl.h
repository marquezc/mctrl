/* mctrl.h - Motor Control Header File */

/* -------------------------------------------------------------------------- */
/*  MCTRL General -------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

#define ON 1
#define OFF 0

#define MAX_NAME 32

/* -------------------------------------------------------------------------- */
/*  Connection and Nodes (MCU, MCTRL) --------------------------------------- */
/* -------------------------------------------------------------------------- */

#define UDP 0;
#define TCP 1;

typedef struct mcu
{
  int id; // Unique [integer] Mcu identifier > 0;
  char name[MAX_NAME];  // MCU name;
  unsigned int ip; // MCU IP address;
} Mcu;

typedef struct mctrl
{
  int id; // Unique [integer] Mcu identifier > 0;
  char name[MAX_NAME]; // MCTRL name;
  unsigned int ip; // MCTRL IP address;
} Mctrl;

typedef struct cxn
{
  int id; // Unique [integer] connection identifier > 0;
  char name[MAX_NAME]; // Connection name;
  int state; // Connection state (ON/OFF);
  Mcu mcu; // Connection MCU identifier;
  Mctrl mctrl; // Connection MCTRL identifier;
  int protocol; // {UDP, TCP};
} Cxn;

/* mctrl_connect()
   Connect the movement control node (MCTRL) to the 
   master control unit (MCU).  */

void mctrl_connect(Cxn *m_cxn, Mcu *m_mcu, Mctrl *m_mctrl, int protocol);

/* mctrl_connection_status()
   Return the connection status of the MCTRL node. */
int mctrl_connection_status(Cxn *m_cxn);


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

   
