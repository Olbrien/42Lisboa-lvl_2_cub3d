/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:43:50 by tisantos          #+#    #+#             */
/*   Updated: 2021/03/12 05:50:15 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define NOEVENTMASK				0
# define KEYPRESSMASK				1
# define KEYRELEASEMASK				2
# define BUTTONPRESSMASK			3
# define BUTTONRELEASEMASK			4
# define ENTERWINDOWMASK			5
# define LEAVEWINDOWMASK			6
# define POINTERMOTIONMASK			7
# define POINTERMOTIONHINTMASK		8
# define BUTTON1MOTIONMASK			9
# define BUTTON2MOTIONMASK			10
# define BUTTON3MOTIONMASK			11
# define BUTTON4MOTIONMASK			12
# define BUTTON5MOTIONMASK			13
# define BUTTONMOTIONMASK			14
# define KEYMAPSTATEMASK			15
# define EXPOSUREMASK				16
# define VISIBILITYCHANGEMASK		17
# define STRUCTURENOTIFYMASK		18
# define RESIZEREDIRECTMASK			19
# define SUBSTRUCTURENOTIFYMASK		20
# define SUBSTRUCTUREREDIRECTMASK	21
# define FOCUSCHANGEMASK			22
# define PROPERTYCHANGEMASK			23
# define COLORMAPCHANGEMASK			24
# define OWNERGRABBUTTONMASK		25

# define KEYPRESS					2
# define KEYRELEASE					3
# define BUTTONPRESS				4
# define BUTTONRELEASE				5
# define MOTIONNOTIFY				6
# define ENTERNOTIFY				7
# define LEAVENOTIFY				8
# define FOCUSIN					9
# define FOCUSOUT					10
# define KEYMAPNOTIFY				11
# define EXPOSE						12
# define GRAPHICSEXPOSE				13
# define NOEXPOSE					14
# define VISIBILITYNOTIFY			15
# define CREATENOTIFY				16
# define DESTROYNOTIFY				17
# define UNMAPNOTIFY				18
# define MAPNOTIFY					19
# define MAPREQUEST					20
# define REPARENTNOTIFY				21
# define CONFIGURENOTIFY			22
# define CONFIGUREREQUEST			23
# define GRAVITYNOTIFY				24
# define RESIZEREQUEST				25
# define CIRCULATENOTIFY			26
# define CIRCULATEREQUEST			27
# define PROPERTYNOTIFY				28
# define SELECTIONCLEAR				29
# define SELECTIONREQUEST			30
# define SELECTIONNOTIFY			31
# define COLORMAPNOTIFY				32
# define CLIENTMESSAGE				33
# define MAPPINGNOTIFY				34
# define GENERICEVENT				35
# define LASTEVENT					36

#endif
