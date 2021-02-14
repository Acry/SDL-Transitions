# Transitions with SDL2

Transitions from one scene or action to another can be done in a plenty of ways.

They can be done linear or not. See [my repo for non linear animations](https://github.com/Acry/Non-Linear-Animations)

See: 
<https://www.jssor.com/development/tool-slideshow-transition-viewer.html> for all kind of transitions.

Just be aware there is nothing fancy or new in transitions. The math is very old and it has been used for decades. It is just eye candy.

## Cut

one scene instantly replaces the other.

## Fade in/out

gradually replaced by black screen or any other solid color
Fade ins are the opposite: a solid color gradually gives way to picture

## Flashing

Distracts from the current scene.

## Wipe

Wipes are dynamic. They happen when one shot pushes the other off frame.

## Melting

The scene wipes with a melting effect.

## Whip Pan

A whip pan is a type of panning in which the camera pans so quickly that the picture blurs into indistinct streaks. It is commonly used as a transition between shots, and can indicate the passage of time or a frenetic pace of action.

This technique is used liberally by directors Anatole Litvak, Sam Raimi, Wes Anderson and Edgar Wright. It is also frequently seen in 1970s martial arts movies.

## Panning


## Dissolve

Also known as overlapping or cross fade. A dissolve overlaps two scenes, gradually transitioning from one to the other.

Render whatever you're dissolving from to a render target, like a normal draw cycle.
Render whatever you're dissolving *to* to a second render target the size of the screen. (Assuming you're using a dissolve as a transition and not fading to black or another solid color. If you are, it gets simpler.)

Create an array of integers. Its length should be equal to the number of blocks you're going to use in your dissolve. (The maximum size would be the width of your window * the height, if the size of your dissolve block is 1 pixel.) Call it Blocks. 

Fill the array such that for each element, `Blocks[x] = x.` Then shuffle the array randomly. [see](http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle) for a way to do that.

Decide how long the dissolve should take. For each frame:
You want the dissolve to progress by a certain number of pixels. Determine how many, based on the amount of time is left in the dissolve, and call that Count.
You should be keeping an index marker into Blocks that says how far along you are in the dissolve. Take the next Count number of pixel values from Blocks and set the alpha for the corresponding pixel to 0 in the "before" target for each one, advancing the index as you go.
Render the "after" target to the window. (Or fill it with a solid color.)
Render the "before" target on top of it. Wherever the alpha is set to 0, the "after" image will show through.
Once you reach the end of the Blocks array, the dissolve will be complete. 

Draw the first image, update the screen.
Draw the second image, update every other pixel using SDL_UpdateRects
Update the rest of the screen. 

## Zoom effects

### Dolly Zoom Effect

### Roto Zoomer

## Unsorted

Iris
Start by creating an image that acts as the mask part.
choose center  
`SDL_RenderSetClipRect(renderer, &dest);`


- Slide/swipe

- pop in out

- flip hor

- turn ver

- flow

- Parallax Slideshow

- mosaic/tiling/stripes

- wheel

- uncover

- bars

- checkers