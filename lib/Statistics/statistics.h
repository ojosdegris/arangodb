////////////////////////////////////////////////////////////////////////////////
/// @brief statistics basics
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2013 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Copyright 2012-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_STATISTICS_STATISTICS_H
#define TRIAGENS_STATISTICS_STATISTICS_H 1

#include "BasicsC/common.h"
#include "Statistics/figures.h"

// -----------------------------------------------------------------------------
// --SECTION--                                              forward declarations
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// --SECTION--                                                      public types
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Statistics
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief statistics list entry
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_statistics_entry_s {
  struct TRI_statistics_entry_s* _next;
}
TRI_statistics_entry_t;

////////////////////////////////////////////////////////////////////////////////
/// @brief list list
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_statistics_list_s {
  TRI_statistics_entry_t* _first;
  TRI_statistics_entry_t* _last;
}
TRI_statistics_list_t;

////////////////////////////////////////////////////////////////////////////////
/// @brief request statistics
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_request_statistics_s {
  void* _next;

  double _readStart;
  double _readEnd;
  double _queueStart;
  double _queueEnd;
  double _requestStart;
  double _requestEnd;
  double _writeStart;
  double _writeEnd;

  double _receivedBytes;
  double _sentBytes;

  bool _tooLarge;
  bool _executeError;
}
TRI_request_statistics_t;

////////////////////////////////////////////////////////////////////////////////
/// @brief connection statistics
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_connection_statistics_s {
  void* _next;

  bool _http;

  double _connStart;
  double _connEnd;

  bool _error;
}
TRI_connection_statistics_t;

////////////////////////////////////////////////////////////////////////////////
/// @brief global server statistics
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_server_statistics_s {
  double _startTime;
  double _uptime;
}
TRI_server_statistics_t;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                               public request statistics functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Statistics
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief gets a new statistics block
////////////////////////////////////////////////////////////////////////////////

TRI_request_statistics_t* TRI_AcquireRequestStatistics (void);

////////////////////////////////////////////////////////////////////////////////
/// @brief releases a statistics block
////////////////////////////////////////////////////////////////////////////////

void TRI_ReleaseRequestStatistics (TRI_request_statistics_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief fills the current statistics
////////////////////////////////////////////////////////////////////////////////

void TRI_FillRequestStatistics (triagens::basics::StatisticsDistribution& totalTime,
                                triagens::basics::StatisticsDistribution& requestTime,
                                triagens::basics::StatisticsDistribution& queueTime,
                                triagens::basics::StatisticsDistribution& bytesSent,
                                triagens::basics::StatisticsDistribution& bytesReceived);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                            public connection statistics functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Statistics
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief gets a new statistics block
////////////////////////////////////////////////////////////////////////////////

TRI_connection_statistics_t* TRI_AcquireConnectionStatistics (void);

////////////////////////////////////////////////////////////////////////////////
/// @brief releases a statistics block
////////////////////////////////////////////////////////////////////////////////

void TRI_ReleaseConnectionStatistics (TRI_connection_statistics_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief fills the current statistics
////////////////////////////////////////////////////////////////////////////////

void TRI_FillConnectionStatistics (triagens::basics::StatisticsCounter& httpConnections,
                                   triagens::basics::StatisticsDistribution& connectionTime);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                public server statistics functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Statistics
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief gets the server statistics
////////////////////////////////////////////////////////////////////////////////

TRI_server_statistics_t TRI_GetServerStatistics ();

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                  public variables
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Statistics
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief statistics enabled flags
////////////////////////////////////////////////////////////////////////////////

extern bool TRI_ENABLE_STATISTICS;

////////////////////////////////////////////////////////////////////////////////
/// @brief number of http conntections
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsCounter HttpConnections;

////////////////////////////////////////////////////////////////////////////////
/// @brief connection time distribution vector
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsVector ConnectionTimeDistributionVector;

////////////////////////////////////////////////////////////////////////////////
/// @brief total time distribution
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsDistribution* ConnectionTimeDistribution;

////////////////////////////////////////////////////////////////////////////////
/// @brief request time distribution vector
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsVector RequestTimeDistributionVector;

////////////////////////////////////////////////////////////////////////////////
/// @brief total time distribution
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsDistribution* TotalTimeDistribution;

////////////////////////////////////////////////////////////////////////////////
/// @brief request time distribution
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsDistribution* RequestTimeDistribution;

////////////////////////////////////////////////////////////////////////////////
/// @brief queue time distribution
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsDistribution* QueueTimeDistribution;

////////////////////////////////////////////////////////////////////////////////
/// @brief bytes sent distribution vector
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsVector BytesSentDistributionVector;

////////////////////////////////////////////////////////////////////////////////
/// @brief bytes sent distribution
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsDistribution* BytesSentDistribution;

////////////////////////////////////////////////////////////////////////////////
/// @brief bytes received distribution vector
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsVector BytesReceivedDistributionVector;

////////////////////////////////////////////////////////////////////////////////
/// @brief bytes received distribution
////////////////////////////////////////////////////////////////////////////////

extern triagens::basics::StatisticsDistribution* BytesReceivedDistribution;

////////////////////////////////////////////////////////////////////////////////
/// @brief global server statistics
////////////////////////////////////////////////////////////////////////////////

extern TRI_server_statistics_t ServerStatistics;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Statistics
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief gets the current wallclock time
////////////////////////////////////////////////////////////////////////////////

double TRI_StatisticsTime (void);

////////////////////////////////////////////////////////////////////////////////
/// @brief module init function
////////////////////////////////////////////////////////////////////////////////

void TRI_InitialiseStatistics (void);

////////////////////////////////////////////////////////////////////////////////
/// @brief shut down statistics
////////////////////////////////////////////////////////////////////////////////

void TRI_ShutdownStatistics (void);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|/// @page\\|// --SECTION--\\|/// @\\}"
// End:
