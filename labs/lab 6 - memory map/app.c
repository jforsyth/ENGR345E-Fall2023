/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/

//since is modifiable, should end up in RAM
static int evilGlobalVar=0;

//since is static const, will end up in Flash
const static int globalConstantVariable=10;

//since is static const, should end up in Flash
//but is never read so it is removed
const static int neverReferenced=10;

void app_process_action(void)
{

  /**
   * In the line below is an example of a pointer
   * being set to a fixed address. The variable "ptr" should have the
   * value 0x1000031c which means when the pointer is "dereferenced" it should
   * read the data located at memory address 0x1000031c
   */
  int* ptr = (int*)(0x1000031c);

  /**
   * Pointers are typically not hard coded like the line above.
   * The reference operator (&) is used to find the address of some variable
   * or function. An example of this is shown below where the address of "evilGlobalVar"
   * is set the pointer globalVarPtr
   */
  int* globalVarPtr = &evilGlobalVar;
  int setBreakPointHere = 0;


  /**
   * While data can be copied between variables, the address of those variables
   * do not change. In the lines below, information is copied from constantVar into
   * a local variable. While the value of these variables are the same, their
   * locations should be different. Local data (items within this function) and global
   * variables (items outside this function) will reside in different memory locations.
   */
  int localVariable=globalConstantVariable;

  int* localVariablePtr = &localVariable;
  int* globalConstantVarLoc = &globalConstantVariable;

  setBreakPointHere = 10;

  /**
   * Beyond pointers to data, there can also be pointers to functions.
   * app_process_action() is a function that runs the code above. We can create a
   * pointer to see where that set of instruction code is located.
   */
  int (*appProcessAddress)(void) = &app_process_action;

  setBreakPointHere = 20;

}
