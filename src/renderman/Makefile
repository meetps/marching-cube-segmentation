all: multiple

world:
	prman -progress world.rib

clean:
	rm -f renders/*.tif

individual:
	@sed 's/ANGLEX/$(AX)/g' total_world.rib > tworld.rib
	@sed 's/ANGLEY/$(AY)/g' tworld.rib > aworld.rib
	@sed 's/ANGLEZ/$(AZ)/g' aworld.rib > tworld.rib
	@sed 's/FILE/render_$(FILENAME)/g'  tworld.rib > aworld.rib
	@prman aworld.rib
	@rm -f aworld.rib
	@rm -f tworld.rib

multiple:
	sed 's/ANGLE/-90/g' world.rib > aworld.rib
	sed 's/FILE/render_1/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/-60/g' world.rib > aworld.rib
	sed 's/FILE/render_2/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/-30/g' world.rib > aworld.rib
	sed 's/FILE/render_3/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/0/g' world.rib > aworld.rib
	sed 's/FILE/render_4/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/30/g' world.rib > aworld.rib
	sed 's/FILE/render_5/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/60/g' world.rib > aworld.rib
	sed 's/FILE/render_6/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/90/g' world.rib > aworld.rib
	sed 's/FILE/render_7/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/120/g' world.rib > aworld.rib
	sed 's/FILE/render_8/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/150/g' world.rib > aworld.rib
	sed 's/FILE/render_9/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/180/g' world.rib > aworld.rib
	sed 's/FILE/render_10/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/-120/g' world.rib > aworld.rib
	sed 's/FILE/render_11/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	sed 's/ANGLE/-150/g' world.rib > aworld.rib
	sed 's/FILE/render_12/g'  aworld.rib > tworld.rib
	prman -progress tworld.rib

	rm -f aworld.rib
	rm -f tworld.rib


